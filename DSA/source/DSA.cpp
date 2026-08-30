#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include "../Headers/Globals.h"
using namespace std;

int main()
{

	vector<int> nums = { 2, 3, 6, 7, 8, 8, 11, 11, 11, 12 };

	cout << upperBound(nums, 11);

}