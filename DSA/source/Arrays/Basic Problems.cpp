#include <iostream>
#include <vector>
using namespace std;

int greatestElementInTheArray(int a[], int size) {

	int greatest = 0;
	for (int i = 0; i < size; i++) {
		if (a[i] > a[greatest]) {
			greatest = i;
		}
	}

	return a[greatest];

}

vector<int> secondGreatestElementInTheArray(int a[], int size) {

	int greatest = 0, secondGreatest = 0;
	for (int i = 0; i < size; i++) {
		if (a[i] > a[greatest]) {
			secondGreatest = greatest;
			greatest = i;
		}
		else if (a[i] > a[secondGreatest] && a[i] != a[greatest]) {
			secondGreatest = i;
		}
	}

	return {a[greatest], a[secondGreatest]};

}

void removeDuplicates(int a[], int size) {

	int left = 0;
	for (int i = 1; i < size; i++) {

		if (a[i] != a[left]) {

			a[++left] = a[i];
		}

	}

}