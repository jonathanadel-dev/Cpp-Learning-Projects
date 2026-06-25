#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include "../Headers/Globals.h"
using namespace std;

int main()
{

	//vector<vector <int>> matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

	vector<vector<int>> pascals = pascalsTriangle(5);

	for (auto i : pascals) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}

}