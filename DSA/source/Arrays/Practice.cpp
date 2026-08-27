#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
#include <functional>
#include <algorithm>
using namespace std;

vector<int> productOfArrayExceptSelf(vector<int>& nums) {

    vector<int> ans;
    vector<int> prefixProduct;
    vector<int> suffixProduct;
    prefixProduct.push_back(1);
    suffixProduct.push_back(1);
    int n = nums.size();

    for (int i = 1; i < n; i++) {

        int lastPrefix = prefixProduct.back();
        int lastSuffix = suffixProduct.back();
        prefixProduct.push_back(lastPrefix * nums[i - 1]);
        suffixProduct.push_back(lastSuffix * nums[n - i]);

    }

    for (int i = 0; i < n; i++) {
        int prefix = prefixProduct[i];
        int suffix = suffixProduct[n - 1 - i];
        ans.push_back(prefix * suffix);
    }

    return ans;

}


int trappingRainWater(vector<int>& nums) {

    auto myDraft = [&]() {

    };


    auto theSolution = [&]() {
    
    };

}