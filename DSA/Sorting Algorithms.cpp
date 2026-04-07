#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortingFunction() {
	vector<int> v = { 3, 1, 5, 2, 4 };
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < 5; i++) {
		cout << v[i] << " ";
	}
}