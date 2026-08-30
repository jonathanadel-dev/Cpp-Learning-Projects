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


// Binary search
int binarySearch(vector<int>& nums, int target) {

	auto iterativeApproach = [&]() {
		
		int n = nums.size();
		int index = -1, low = 0, high = n - 1;

		while (low <= high) {

			int mid = (low + high) / 2;

			if (nums[mid] == target) {
				return index = mid;
				break;
			}
			else if (nums[mid] > target) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}

		}

		return index;

	};

	auto recursiveApproach = [&]() {
	
		int n = nums.size();

		function<int(int, int)> search = [&](int low, int high) -> int {

			if (low > high) {
				return -1;
			}

			int mid = (low + high) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			else if (nums[mid] > target) {
				return search(low, mid - 1);
			}
			else {
				return search(mid + 1, high);
			}

			return -1;

		};

		return search(0, n - 1);

	};

	return iterativeApproach();

}


// Lower bound
int lowerBound(vector<int>& nums, int target) {

	int n = nums.size();
	int low = 0;
	int high = n - 1;
	int ans = n;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (nums[mid] >= target) {
			ans = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ans;
}


// Upper bound
int upperBound(vector<int>& nums, int target) {

	int n = nums.size();
	int low = 0, high = n - 1, ans = n;

	while (low <= high) {
		int middle = (high + low) / 2;
		if (nums[middle] <= target) {
			low = middle + 1;
		}
		else {
			ans = middle;
			high = middle - 1;
		}
	}

	return ans;

}


// Search insert
int searchInsert(vector<int>& nums, int target) {

	int n = nums.size();
	int low = 0, high = n - 1, ans = n;

	while (low <= high) {
		int middle = (high + low) / 2;
		if (nums[middle] >= target) {
			ans = middle;
			high = middle - 1;
		}
		else {
			low = middle + 1;
		}
	}

	return ans;

}


// Find floor and ceil
vector<int> findFloorAndCeil(vector<int>& nums, int target) {

	vector<int> ans;
	int n = nums.size();
	int low = 0, high = n - 1, floorIndex = -1, ceilIndex = -1;

	while (high >= low) {
		int middle = (high + low) / 2;
		if (nums[middle] < target) {
			floorIndex = middle;
			low = middle + 1;
		} else if (nums[middle] > target) {
			ceilIndex = middle;
			high = middle - 1;
		}
		else {
			floorIndex = middle;
			ceilIndex = middle;
			break;
		}
	}

	ans.push_back(floorIndex == -1 ? -1 : nums[floorIndex]);
	ans.push_back(ceilIndex == -1 ? -1 : nums[ceilIndex]);

	return ans;

}