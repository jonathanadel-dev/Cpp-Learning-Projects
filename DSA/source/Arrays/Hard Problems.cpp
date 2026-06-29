#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
#include <algorithm>
using namespace std;


// Pascal's triangle
vector<vector<int>> pascalsTriangle(int n) {

    vector<vector<int>> nums;

    for (int i = 0; i < n; i++) {

        vector<int> row(i + 1, 1);

        for (int j = 1; j < i; j++) {
            row[j] = nums[i - 1][j - 1] + nums[i - 1][j];
        }

        nums.push_back(row);

    }

    return nums;

};


// Majority element two
vector<int> majorityElementTwo(vector<int> nums) {

    auto betterSolution = [&]() {

        int n = nums.size() / 3;
        vector<int> ans;
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        for (auto i : freq) {
            if (i.second > n) {
                ans.push_back(i.first);
            }
        }

        return ans;

        };

    auto optimalSolution = [&]() {

        vector<int> ans;
        int elOne = INT_MIN, countOne = 0, elTwo = INT_MIN, countTwo = 0, n = nums.size() / 3;

        for (int i = 0; i < nums.size(); i++) {
            if (countOne == 0 && nums[i] != elTwo) {
                countOne = 1;
                elOne = nums[i];
            }
            else if (countTwo == 0 && nums[i] != elOne) {
                countTwo = 1;
                elTwo = nums[i];
            }
            else if (nums[i] == elOne) {
                countOne++;
            }
            else if (nums[i] == elTwo) {
                countTwo++;
            }
            else {
                countOne--;
                countTwo--;
            }
        }

        countOne = 0;
        countTwo = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == elOne) countOne++;
            if (nums[i] == elTwo) countTwo++;
        }

        if (countOne > n) {
            ans.push_back(elOne);
        }

        if (countTwo > n) {
            ans.push_back(elTwo);
        }

        return ans;

    };

    return betterSolution();

}


// Three sum
vector<vector<int>> threeSum(vector<int> nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++) {
        // Skip duplicates for i
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int j = i + 1, k = nums.size() - 1;

        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                ans.push_back({ nums[i], nums[j], nums[k] });
                // Skip duplicates for j and k
                while (j < k && nums[j] == nums[j + 1]) j++;
                while (j < k && nums[k] == nums[k - 1]) k--;
                j++;
                k--;
            }
        }
    }

    return ans;
}