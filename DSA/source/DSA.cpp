#include <iostream>
#include <vector>
#include "../Headers/Globals.h"
using namespace std;

int main()
{

	//int a[] = { 0, 1, 0, 1, 1, 3, 3, 0, 0, 0, 4, 8, 9, 9, 10, 0 };
	//int size = sizeof(a) / sizeof(a[0]);

	vector<int> a1 = { 1, 2, 4, 2, 4, 5, 1 };
	vector<int> a2 = { 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1 };

	cout << findTheElementThatAppearsOnce(a1);

	//vector<int> v = intersectionOfTwoArrays(a1, a2);

	//for (auto i : v) {
	//	cout << i << " ";
	//}

}