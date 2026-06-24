#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
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


// Set matrix zeros
void setMatrixZeros(vector<vector <int>> matrix) {

    set<int> rows = {};
    set<int> cols = {};

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 0) {
                rows.emplace(i);
                cols.emplace(j);
            }
        }
    }

    for (auto i : rows) {
        for (int j = 0; j < matrix[0].size(); j++) {
            matrix[i][j] = 0;
        }
    }

    for (auto i : cols) {
        for (int j = 0; j < matrix.size(); j++) {
            matrix[j][i] = 0;
        }
    }

}


// Rotate matrix brute solution
vector<vector <int>> rotateMatrixBruteSolution(vector<vector<int>> matrix) {

    int n = matrix.size();

    vector<vector <int>> newMat(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int newJ = (n - 1) - i;
            newMat[j][newJ] = matrix[i][j];
        }
    }

    return newMat;

}


// Rotate matrix optimal solution
void rotateMatrixOptimalSolution(vector<vector<int>> &matrix) {

    int n = matrix.size();

    // Transposing the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }


    // Reversing the rows
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n/2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][n-j-1];
            matrix[i][n-j-1] = temp;
        }
    }

}


// Spiral matrix
vector<int> spiralMatrix(vector<vector<int>> matrix) {

    vector<int> nums;
    char direction = 'r';
    int row = 0,
        col = 0,
        m = matrix.size(),
        n = matrix[0].size(),
        currentTurn = 0,
        noOfRuns = 0;

    while (noOfRuns < m * n) {

        // Adding the number
        nums.push_back(matrix[row][col]);


        // Switching directions
        if (row == currentTurn && col == n - currentTurn - 1 && direction == 'r') {
            direction = 'd';
        }
        else if (row == m - currentTurn - 1 && col == n - currentTurn - 1 && direction == 'd') {
            direction = 'l';
        }
        else if (row == currentTurn && col == currentTurn - 1 && direction == 'u') {
            direction = 'r';
        }
        else if (row == m - currentTurn - 1 && col == currentTurn && direction == 'l') {
            direction = 'u';
            currentTurn++;
        }


        // Moving the pointer
        switch (direction) {
        case 'r':
            col++;
            break;
        case 'd':
            row++;
            break;
        case 'l':
            col--;
            break;
        case 'u':
            row--;
            break;
        default:
            cout << "Invalid direction";
        };


        // Incrementing the number of runs
        noOfRuns++;

    }

    return nums;

}


// Number of subarrays with sum k
int numberOfSubarraysWithSumK(vector<int> nums, int k) {

    unordered_map<int, int> prefixSums;
    prefixSums[0] = 1;
    int sum = 0, n = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (prefixSums.count(sum - k)) {
            n += prefixSums[sum - k];
        }
        prefixSums[sum]++;
    }

    return n;

}