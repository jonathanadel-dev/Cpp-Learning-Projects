#include <iostream>
#include <vector>
#include "../Headers/Globals.h"
using namespace std;

int main()
{

	//int a[] = { 0, 1, 0, 1, 1, 3, 3, 0, 0, 0, 4, 8, 9, 9, 10, 0 };
	//int size = sizeof(a) / sizeof(a[0]);

	int a1[] = { 1, 1, 5, 6, 7, 8, 10 };
	int a2[] = { 1, 2, 3, 4, 4, 4, 6, 7, 9 };
	int size1 = sizeof(a1) / sizeof(a1[0]);
	int size2 = sizeof(a2) / sizeof(a2[0]);

	set<int> s = unionOfTwoArrays(a1, a2, size1, size2);

	for (auto i : s) {
		cout << i << " ";
	}

	//for (int i = 0; i < size; i++) {
	//	cout << a[i] << " ";
	//}

}