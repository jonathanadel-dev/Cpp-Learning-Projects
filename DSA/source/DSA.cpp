#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include "../Headers/Globals.h"
using namespace std;

int main()
{

	vector<int> nums = { 2, 3, 3, 4, 5 };

	vector<int> ans = findRepeatingAndMissingNumbers(nums);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

}