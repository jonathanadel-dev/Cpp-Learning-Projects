#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


// 2 Sum problem
vector <int> twoSum(vector <int> v, int target) {

    auto bruteSolution = [&]() {

        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (v[j] == v[i]) {
                    return vector<int> { j, i };
                }
            }
            v[i] = target - v[i];
        }

    };

    auto optimalSolution = [&]() {

        sort(v.begin(), v.end());

        int left = 0, right = v.size() - 1;

        while (left < right) {
            int sum = v[left] + v[right];
            if (sum == target) {
                return vector<int>{ 1 };
            }
            else if(sum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return vector <int> { 0 };

    };

    return optimalSolution();

};


// Sort arrays of 0's, 1's and 2's
void sortArrayOfZerosOnesAndTwos(vector <int> nums) {

    auto optimalSolution = [&]() {

        int left = 0, middle = 0, right = nums.size() - 1;

        while (middle <= right) {
            if (nums[middle] == 0) {
                int temp = nums[left];
                nums[left] = nums[middle];
                nums[middle] = temp;
                left++;
                middle++;
            }
            else if (nums[middle] == 1) {
                middle++;
            }
            else {
                int temp = nums[middle];
                nums[middle] = nums[right];
                nums[right] = temp;
                right--;
            }
        }

    };

    optimalSolution();

}


// Majority element
int majorityElement(vector <int> nums) {


    auto goodSolution = [&]() {

        map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            if (freq[nums[i]] > (nums.size() / 2)) {
                return nums[i];
            }
        }

        return -1;

    };


    // Moore's voting algorithm
    auto optimalSolution = [&]() {

        int count = 0, el = 0;
        for (int i = 0; i < nums.size(); i++) {
            
            if (count == 0) {
                el = nums[i];
            }

            if (nums[i] == el) {
                count++;
            }
            else {
                count--;
            }

        }

        return el;

    };

    return optimalSolution();

}