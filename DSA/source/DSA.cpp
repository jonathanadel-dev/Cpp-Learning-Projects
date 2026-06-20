#include <iostream>
#include <vector>
#include <algorithm>
#include "../Headers/Globals.h"
using namespace std;

int main()
{

	vector<int> nums = { 0,3,7,2,5,8,4,6,0,1 };

	cout << longestConsecutiveSequence(nums);

	//for (auto i : leaders) {
	//	cout << i << " ";
	//}

}