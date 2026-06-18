#include <iostream>
#include <vector>
#include <algorithm>
#include "../Headers/Globals.h"
using namespace std;

int main()
{

	vector<int> v = { 3, 1, 2 };

	cout << *(v.begin() + 2);

	//sort(v.end() - 3, v.end());

	//nextPermutation(v);

	//for (auto i : v) {
	//	cout << i << " ";
	//}

}