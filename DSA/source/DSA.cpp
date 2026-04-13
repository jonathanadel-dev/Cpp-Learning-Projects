#include <iostream>
#include <vector>
#include "../Headers/Globals.h"
using namespace std;

int main()
{

	int a[] = { 1, 1, 1, 3, 3, 4, 8, 9, 9, 10 };
	int size = sizeof(a) / sizeof(a[0]);

	removeDuplicates(a, size);

	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}

}