#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Digits
int numberOfDigits(int n) {
	int count = 0;
	while (n != 0) {
		count++;
		n /= 10;
	}
	return count;
	// O(log_10 n)
}
int numberOfDigits2(int n) {
	return log10(n) + 1;
	// O(log_10 n)
}


// Is armstrong
bool isArmstrong(int n) {
	int sum = 0;
	int temp = n;
	while (n > 0) {
		int digit = n % 10;
		sum += digit * digit * digit;
		n /= 10;
	}
	return temp == sum;
}


// Divisors
void printDivisors(int n) {
	for (int i = 1; i <= n; i++) {
		if (n % i == 0)
			cout << i << " ";
	}
}
void printDivisors2(int n) {
	vector<int> nums;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			nums.emplace_back(i);
			if (i != (n / i)) {
				nums.emplace_back(n / i);
			}
		}
	}
	sort(nums.begin(), nums.end());
	for (auto i : nums) {
		cout << i << " ";
	}
}


// Check if prime
bool isPrime(int n) {
	bool isNPrime = true;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			isNPrime = false;
			break;
		}
	}
	return isNPrime;
}
bool isPrime2(int n) {
	bool isNPrime = true;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			isNPrime = false;
			break;
		}
	}
	return isNPrime;
}


// Greatest common denominator
int gcd(int n1, int n2) {
	while (n1 > 0 && n2 > 0) {
		if (n1 > n2) {
			n1 = n1 % n2;
		}
		else {
			n2 = n2 % n1;
		}
		if (n1 == 0)
			return n2;
		else
			return n1;
	}
	return 0;
}