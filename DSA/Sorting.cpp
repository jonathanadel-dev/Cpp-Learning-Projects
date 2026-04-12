#include <iostream>
#include <vector>
using namespace std;

void selectionSort(int a[], int size) {

	for (int i = 0; i < size - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (a[j] < a[minIndex]) {
				minIndex = j;
			}
		}
		int temp = a[minIndex];
		a[minIndex] = a[i];
		a[i] = temp;
	}

}

void bubbleSort(int a[], int size) {

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

}
void bubbleSort2(int a[], int size) {
	int count = 0;
	for (int i = size - 1; i >= 0; i--) {
		bool isSorted = true;
		count++;
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				isSorted = false;
			}
		}
		if (isSorted) break;
	}
	cout << count << endl;

}

void insertionSort(int a[], int size) {

	for (int i = 0; i < size; i++) {
		int j = i;
		while (j > 0 && a[j] < a[j - 1]) {
			int temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
			j--;
		}
	}

}

void mergingArrays(int a[], int left, int mid, int right) {

	vector <int> temp;

	int low = left, high = mid + 1;

	while (low <= mid && high <= right) {
		if (a[low] <= a[high]) {
			temp.push_back(a[low]);
			low++;
		}
		else {
			temp.push_back(a[high]);
			high++;
		}
	}

	while (low <= mid) {
		temp.push_back(a[low]);
		low++;
	}

	while (high <= right) {
		temp.push_back(a[high]);
		high++;
	}

	for (int i = left; i <= right; i++) {
		a[i] = temp[i - left];
	}

}
void mergeSort(int a[], int left, int right) {

	if (left >= right) return;

	int mid = (right + left) / 2;
	mergeSort(a, left, mid);
	mergeSort(a, mid + 1, right);
	mergingArrays(a, left, mid, right);

}

int findPartation(int a[], int left, int right) {

	int i = left, j = right;
	while (i < j) {

		while (a[i] <= a[left] && i <= right - 1) {
			i++;
		}

		while (a[j] > a[left] && j >= left + 1) {
			j--;
		}

		if (i < j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}

	}

	int temp = a[left];
	a[left] = a[j];
	a[j] = temp;

	return j;

}
void quickSort(int a[], int left, int right) {

	if (left < right) {
		int partation = findPartation(a, left, right);
		quickSort(a, left, partation - 1);
		quickSort(a, partation + 1, right);
	};


}

/*

	Selection sort: Find the smallest number and place in the beginning of the array

	Bubble sort: Switch if the number is greater than the one after it, so that the largest number would be in the end of the array by the first outer loop iteration

	Insertion sort: Find the number's position with respect to the previous numbers in the array (Which are sorted)

	Merge sort: Dividing the array into 2 smaller arrays, then merge them together with sorting. It's a recursive approach

	Quick sort: Positioning an element in it's sorted position (pivot)

*/