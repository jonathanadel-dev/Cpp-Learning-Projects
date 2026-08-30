#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include "../Headers/Globals.h"
using namespace std;

int main()
{

	vector<int> nums = { 2, 4, 6, 8, 10, 12, 14 };

	vector<int> ans = findFloorAndCeil(nums, 1);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

}