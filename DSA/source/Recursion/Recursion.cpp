#include <iostream>
using namespace std;

void print(int i, int n) {
	if (i > n)
		return;

	print(i + 1, n);
	cout << i <<  endl;
}

void printAsc(int i, int n) {
	if (i > n)
		return;
	cout << i << endl;
	printAsc(i + 1, n);
}

void printDesc(int n) {
	if (n < 1)
		return;
	cout << n << endl;
	printDesc(n - 1);
}

void printAsc2(int n) {
	if(n > 1)
		printAsc2(n - 1);
	cout << n << endl;
}

void printDesc2(int i, int n) {
	if (i > n)
		return;
	printDesc2(i + 1, n);
	cout << i << endl;
}

int recursionSum(int n, int sum) {
	if (n < 1) {
		return sum;
	}
	recursionSum(--n, sum + n);
}

int recursionSum2(int n) {
	if (n < 2) {
		return n;
	}
	return n + recursionSum2(n - 1);
}

int recursionFactorial(int n) {
	if (n == 1)
		return n;
	return n * recursionFactorial(n - 1);
}

void recursionArrayReverse(int arr[], int i, int size) {

	int temp = arr[size];
	arr[size] = arr[i];
	arr[i] = temp;

	if (i < size) {
		recursionArrayReverse(arr, i + 1,  size - 1);
	}

}

void recursionArrayReverse2(int arr[], int i, int size) {

	if (i >= size / 2) {
		return;
	}

	//int temp = arr[size - i - 1];
	//arr[size - i - 1] = arr[i];
	//arr[i] = temp;
	swap(arr[i], arr[size - i - 1]);
	recursionArrayReverse2(arr, i + 1, size);

}

bool recursionCheckIfPalindrome(int i, const string& s) {

	if (i >= s.size() / 2) {
		return true;
	}

	if (s[i] != s[s.size() - i - 1]) {
		return false;
	}

	return recursionCheckIfPalindrome(i + 1, s);

}

int recursionFib(int n) {

	if (n == 0) return 0;
	if (n == 1) return 1;
	return recursionFib(n - 1) + recursionFib(n - 2);

}