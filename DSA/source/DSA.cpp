#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include "../Headers/Globals.h"
using namespace std;

int main()
{

	vector<vector <int>> matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

	vector<int> ans = spiralMatrix(matrix);

	//for (auto i : test) {
	//	cout << i << " ";
	//}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

}