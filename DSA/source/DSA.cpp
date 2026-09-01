#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include "../Headers/Globals.h"
using namespace std;

int main()
{

	vector<int> nums = { 0, 0, 1, 1, 1, 2, 3 };

	cout << countOccurences(nums, 5);

}