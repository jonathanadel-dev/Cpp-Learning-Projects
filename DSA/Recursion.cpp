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