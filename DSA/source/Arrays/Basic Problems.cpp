#include <iostream>
#include <vector>
#include <set>
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

void leftRotateAnArrayByOne(int a[], int size) {

	int temp = a[0];

	for (int i = 0; i < size; i++) {
		a[i] = a[i + 1];
	}

	a[size - 1] = temp;

}

void leftRotateAnArrayByK(int a[], int size, int k) {
	
	// My initial answer
	auto myApproach = [&]() {
		
		while ((k % size) > 0) {

			int temp = a[0];

			for (int i = 0; i < size; i++) {
				a[i] = a[i + 1];
			}

			a[size - 1] = temp;

			k--;

		}
	};


	// Brute solution
	auto bruteSolution = [&]() {

		int rotations = k % size;
		vector<int> temp;
		for (int i = 0; i < rotations; i++) {
			temp.push_back(a[i]);
		}
		for (int i = rotations; i < size; i++) {
			a[i - rotations] = a[i];
		}
		for (int i = size - rotations; i < size; i++) {
			a[i] = temp[i - (size - rotations)];
		}

	};


	// Optimal solution
	auto optimalSolution = [&]() {

		int d = k % size;
		
		auto reverse = [&](int left, int right) {
			while (left < right) {
				int temp = a[left];
				a[left] = a[right];
				a[right] = temp;
				left++;
				right--;
			}
		};

		reverse(0, d - 1);
		reverse(d, size - 1);
		reverse(0, size - 1);

	};


	optimalSolution();

}

void movingZerosToTheEnd(int a[], int size) {

	int left = -1;

	for (int i = 0; i < size; i++) {
		if (a[i] != 0) {
			a[++left] = a[i];
			a[i] = 0;
		}
	}

}

set<int> unionOfTwoArrays(int a1[], int a2[], int size1, int size2) {

	// Brute solution
	auto bruteSolution = [&]() {
		set<int> unified;

		for (int i = 0; i < size1; i++) {
			unified.insert(a1[i]);
		}

		for (int i = 0; i < size2; i++) {
			unified.insert(a2[i]);
		}

		return unified;
	};



	return bruteSolution();

}