#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <list>
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


// Maximum subarray
int maximumSubarray(vector<int> nums) {

    auto bruteSolution = [&]() {
        
        int maxSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += nums[k];
                    if (sum > maxSum) {
                        maxSum = sum;
                    }
                }
            }
        }

        return maxSum;
    
    };

    auto betterSolution = [&]() {

        int maxSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum > maxSum) {
                    maxSum = sum;
                }
            }
        }

        return maxSum;

    };

    // Kadane's algorithm
    auto optimalSolution = [&]() {

        int maxSum = -100000000, sum = 0;

        for (int i = 0; i < nums.size(); i++) {

            sum += nums[i];

            if (sum > maxSum) maxSum = sum;

            if (sum < 0) sum = 0;

        }

        return maxSum;

    };

    return optimalSolution();

}


// Rearrange array elements by sign
vector<int> rearrangeArrayElementsBySign(vector<int> nums) {

    auto bruteSolution = [&]() {

        vector<int> ans;
        queue<int> positiveInts, negativeInts;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                positiveInts.push(nums[i]);
            }
            else {
                negativeInts.push(nums[i]);
            }
        }

        for (int i = 0; i < nums.size() / 2; i++) {
            ans.emplace_back(positiveInts.front());
            positiveInts.pop();
            ans.emplace_back(negativeInts.front());
            negativeInts.pop();
        }

        return ans;

    };

    auto optimalSolution = [&]() {

        vector<int> ans(nums.size(), 0);
        int posI = 0, negI = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans[posI] = nums[i];
                posI += 2;
            }
            else {
                ans[negI] = nums[i];
                negI += 2;
            }
        }

        return ans;

     };

    return optimalSolution();

}


// Next permutation
void nextPermutation(vector <int> nums) {

    if (nums.size() <= 1) {
        return;
    }

    int left = -1;

    for (int i = nums.size() - 1; i > 0; i--) {
        if (nums[i] > nums[i - 1]) {
            left = i - 1;
            break;
        }
    }

    if (left == -1) {

        sort(nums.begin(), nums.end());

    }
    else {

        // Swapping the two numbers
        for (int i = nums.size() - 1; i > left; i--) {
            if (nums[i] > nums[left]) {
                int temp = nums[left];
                nums[left] = nums[i];
                nums[i] = temp;
                break;
            }
        }


        // Sorting the after segment
        sort(nums.begin() + left + 1, nums.end());

    }

};


// Leaders in an array
vector <int> leadersInAnArray(vector <int> nums) {

    int greatest = INT_MIN;
    vector <int> leaders;

    for (int i = nums.size() - 1; i >= 0; i--) {
        if (nums[i] > greatest) {
            leaders.push_back(nums[i]);
            greatest = nums[i];
        }
    }

    return leaders;

}


// Longest consecutive sequence
int longestConsecutiveSequence(vector<int> nums) {

    map<int, int> hashMap{};
    int length = 0, lastIndex = 0, maxLength = 0;

    for (int i = 0; i < nums.size(); i++) {
        hashMap[nums[i]] = 1;
    }
    
    for (auto i : hashMap) {
        if (i.first > lastIndex + 1) {
            length = 1;
        }
        else {
            length++;
            if (length > maxLength) {
                maxLength = length;
            }
        }

        lastIndex = i.first;
    }

    return maxLength;

}