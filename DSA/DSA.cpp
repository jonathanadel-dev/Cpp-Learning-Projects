#include <iostream>
#include <vector>
#include "Globals.h"
using namespace std;

int main()
{

	int a[] = { 1, 1, 1, 3, 8, 3, 9, 7, 8, 1 };
	int size = sizeof(a) / sizeof(a[0]);

	quickSort(a, 0, size - 1);

	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}

}