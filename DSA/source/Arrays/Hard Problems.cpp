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