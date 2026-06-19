#include <iostream>
#include <vector>
#include <algorithm>
#include "../Headers/Globals.h"
using namespace std;

int main()
{

	vector<int> nums = { 10, 22, 12, 3, 0, 6 };

	vector <int> leaders = leadersInAnArray(nums);

	for (auto i : leaders) {
		cout << i << " ";
	}

}