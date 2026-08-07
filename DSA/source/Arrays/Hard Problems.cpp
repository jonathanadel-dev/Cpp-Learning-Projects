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


// Four sum
vector<vector<int>> fourSum(vector<int> nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n - 3; i++) {

        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < n - 2; j++) {

            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            int k = j + 1, l = n - 1;

            while (k < l) {

                long long sum = nums[i] + nums[j];
                sum += nums[k];
                sum += nums[l];

                if (sum > target) {
                    int currentL = nums[l];
                    while (currentL == nums[l] && l > k) l--;
                }
                else if (sum < target) {
                    int currentK = nums[k];
                    while (currentK == nums[k] && k < l) k++;
                }
                else {

                    vector<int> temp = { nums[i], nums[j], nums[k], nums[l] };
                    ans.push_back(temp);

                    int currentL = nums[l];
                    while (currentL == nums[l] && l > k) l--;
                    int currentK = nums[k];
                    while (currentK == nums[k] && k < l) k++;

                }

            }
        }
    }

    return ans;
}


// Longest subarray with sum k
int longestSubarrayWithSumK(vector<int> nums, int k) {

    int sum = 0, n = 0;
    unordered_map<int, int> prefixSum;

    for (int i = 0; i < nums.size(); i++) {

        sum += nums[i];

        if (sum == k) {
            if (i + 1 > n) {
                n = i + 1;
            }
        }

        int rem = sum - k;
        if (prefixSum.find(rem) != prefixSum.end()) {
            if (i - prefixSum[rem] > n) {
                n = i - prefixSum[rem];
            }
        }

        if (prefixSum.find(sum) == prefixSum.end()) {
            prefixSum[sum] = i;
        }

    }

    return n;


}


// Count subarrays with given XOR k
int countSubarraysWithGivenXORK(vector<int> nums, int k) {

    int n = 0, sum = 0;
    unordered_map<int, int> prefixSum;
    prefixSum[0] = 1;

    for (int i = 0; i < nums.size(); i++) {

        sum = sum ^ nums[i];

        int rem = sum ^ k;
        if (prefixSum.find(rem) != prefixSum.end()) {
            n += prefixSum[rem];
        }

        prefixSum[sum]++;

    }

    return n;

}


// Merge intervals
vector<vector<int>> mergeIntervals(vector<vector<int>> intervals) {

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> newIntervals;

    for (int i = 0; i < intervals.size(); i++) {

        if (i == 0) {
            vector<int> temp = { intervals[i][0], intervals[i][1] };
            newIntervals.push_back(temp);
            continue;
        }

        if (intervals[i][0] <= newIntervals.back()[1]) {
            if (intervals[i][1] > newIntervals.back()[1]) {
                newIntervals.back()[1] = intervals[i][1];
            }
        }
        else {
            vector<int> temp = { intervals[i][0], intervals[i][1] };
            newIntervals.push_back(temp);
        }

    }

    return newIntervals;

}


// Merge sorted array
void mergeSortedArray(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    if (n == 0) {
        return;
    }

    if (m == 0) {
        for (int i = 0; i < n; i++) {
            nums1[i] = nums2[i];
        }
        return;
    }

    auto solutionOne = [&]() {

        int index = 0;

        while (index < n && index <= m - 1 && nums1[m - 1 - index] > nums2[index]) {

            int temp = nums1[m - 1 - index];
            nums1[m - 1 - index] = nums2[index];
            nums2[index] = temp;

            index++;

        }

        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.end());

        for (int i = m; i < m + n; i++) {
            nums1[i] = nums2[i - m];
        }

    };

    auto solutionTwo = [&]() {
        
        float gap = ceil((m + n) / 2);

        while (true) {
            int left = 0, right = left + gap;
            while (right < m + n) {
                if (left >= m) {
                    if (nums2[left - m] > nums2[right - m]) {
                        swap(nums2[left - m], nums2[right - m]);
                    }
                }
                else {
                    if (right >= m) {
                        if (nums1[left] > nums2[right - m]) {
                            swap(nums1[left], nums2[right - m]);
                        }
                    }
                    else {
                        if (nums1[left] > nums1[right]) {
                            swap(nums1[left], nums1[right]);
                        }
                    }
                }
                left++; right++;
            }
            if (gap == 1) {
                break;
            }
            else {
                gap = ceil(gap / 2);
            }
        }

        for (int i = m; i < m + n; i++) {
            nums1[i] = nums2[i - m];
        }

    };

    solutionOne();

}


// Find the reapeating and missing numbers
vector<int> findRepeatingAndMissingNumbers(vector<int> nums) {

    int n = nums.size();
    vector<int> ans = { -1, -1 }; // {repeating, missing}
    sort(nums.begin(), nums.end());

    if (nums[0] != 1) ans[1] = 1;
    if (nums[n - 1] != n && ans[1] == -1) ans[1] = n;

    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i - 1]) {
            ans[0] = nums[i];
        }
        else if (nums[i] - nums[i - 1] == 2) {
            ans[1] = nums[i] - 1;
        }
    }

    return ans;

}


// Count inversions in an array
long long merge(vector<int>&arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;
    long long count = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        }
        else {
            // arr[left..mid] are all > arr[right] (left half is sorted)
            count += (mid - left + 1);
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= high) temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++) arr[i] = temp[i - low];
    return count;
}
long long mergeSort(vector<int>&arr, int low, int high) {
    long long count = 0;
    if (low >= high) return count;
    int mid = (low + high) / 2;
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += merge(arr, low, mid, high);
    return count;
}
long long countInversions(vector<int>&arr) {
    return mergeSort(arr, 0, arr.size() - 1);
}