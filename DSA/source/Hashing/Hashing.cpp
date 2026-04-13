#include <iostream>
#include <string>
#include <map>
using namespace std;

void hashingArray(int a[], int size) {

	int frequencyArray[1000] = {};

	for (int i = 0; i < size; i++) {
		frequencyArray[a[i]]++;
	}

	for (int i = 0; i < size; i++) {
		cout << i << " => " << frequencyArray[i] << endl;
	}

}

void hashingCharacters(string s) {

	int a[256] = {};

	for (int i = 0; i < s.size(); i++) {
		a[s[i]]++;
	}

	for (int i = 0; i < 256; i++) {
		if (a[i] > 0) {
			cout << (char)i << " => " << a[i] << endl;
		}
	}

}

void hashingMap(int a[], int size) {

	map<int, int> m;

	for (int i = 0; i < size; i++) {
		m[a[i]]++;
	}

	for (auto &[key, value] : m) {
		cout << key << " => " << value << endl;
	}

}

void hashingCharacterMap(string s) {

	map<char, int> m;

	for (int i = 0; i < s.size(); i++) {
		m[s[i]]++;
	}

	for (auto& [key, value] : m) {
		cout << key << " => " << value << endl;
	}

}