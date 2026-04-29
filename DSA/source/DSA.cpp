#include <iostream>
#include <vector>
#include "../Headers/Globals.h"
using namespace std;

int main()
{

	vector<int> v = { 1, 0, 2, 0, 0, 2, 0, 1, 0, 0, 2, 0 };

	//vector <int> nums = sortArrayOfZerosOnesAndTwos(v);
	cout << majorityElement(v);

	//for (auto i : v) {
	//	cout << i << " ";
	//}

}