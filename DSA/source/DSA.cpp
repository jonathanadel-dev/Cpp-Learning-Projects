#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include "../Headers/Globals.h"
using namespace std;

int main()
{

	vector<int> nums = { 3, 2, 3 };

	vector<int> majs = majorityElementTwo(nums);

	for (int i = 0; i < majs.size(); i++) {
		cout << majs[i] << " ";
	}

}