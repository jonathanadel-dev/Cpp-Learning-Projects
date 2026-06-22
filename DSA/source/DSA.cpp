#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include "../Headers/Globals.h"
using namespace std;

int main()
{

	vector<vector <int>> matrix = {{1, 2, 3}, { 4, 5, 6 }, { 7, 8, 9 }};

	rotateMatrixOptimalSolution(matrix);

	//for (auto i : test) {
	//	cout << i << " ";
	//}

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

}