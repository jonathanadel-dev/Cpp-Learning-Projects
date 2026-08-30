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


int trappingRainWater(vector<int>& height) {

    auto myDraft = [&]() {

        int left = 0, maxRightHeight = -1, waterArea = 0;

        auto calculateArea = [&](int left, int right) {

            int theWidth = right - left - 1;
            int theHeight = min(height[left], height[right]);
            int area = theWidth * theHeight;

            for (int i = left + 1; i < right; i++) {
                area -= height[i];
            }

            waterArea += area;

        };

        for (int i = 0; i < height.size(); i++) {

            if ((i > 0) && (height[i] >= height[left])) {

                // Calculate area
                calculateArea(left, i);

                left = i;

                maxRightHeight = -1;

                continue;

            }

            if ((i > 0) && (height[i] > height[i - 1])) {
                if (maxRightHeight == -1) {
                    maxRightHeight = i;
                }
                else if (height[maxRightHeight] < height[i]) {
                    maxRightHeight = i;
                }
            }

        }

        // Calculate are between left and max right height
        if (maxRightHeight != -1) {
            int maxFromRight = maxRightHeight - 1;
            while (maxFromRight > left) {
                if (height[maxFromRight] >= height[maxRightHeight]) {
                    break;
                }
                else {
                    maxFromRight--;
                }
            }
            calculateArea(maxFromRight, maxRightHeight);
        }


        return waterArea;

    };


    auto theSolution = [&]() {
        int n = height.size();
        int area = 0, left = 0, right = n - 1, maxLeft = height[left], maxRight = height[right];

        while (left <= right) {
            if (maxLeft < maxRight) {
                int addArea = maxLeft - height[left];
                if (addArea > 0) {
                    area += addArea;
                }
                maxLeft = max(maxLeft, height[left]);
                left++;
            }
            else {
                int addArea = maxRight - height[right];
                if (addArea > 0) {
                    area += addArea;
                }
                maxRight = max(maxRight, height[right]);
                right--;
            }
        }

        return area;
    };

    return theSolution();

}