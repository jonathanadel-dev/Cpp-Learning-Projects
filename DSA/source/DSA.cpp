#include <iostream>
#include <vector>
#include "../Headers/Globals.h"
using namespace std;

int main()
{

	//int a[] = { 0, 1, 0, 1, 1, 3, 3, 0, 0, 0, 4, 8, 9, 9, 10, 0 };
	//int size = sizeof(a) / sizeof(a[0]);

	vector<int> a1 = { 1, 1, 5, 6, 7, 8, 10 };
	vector<int> a2 = { 1, 2, 3, 4, 4, 4, 6, 7, 9 };

	vector<int> v = intersectionOfTwoArrays(a1, a2);

	for (auto i : v) {
		cout << i << " ";
	}

}