#include <iostream>
#include <vector>
#include "../Headers/Globals.h"
using namespace std;

int main()
{

	vector<int> v = { 1, 5, 3, 2, 2, 5, 1, 2, 1, 4, 1, 1, 2, 3, 1};

	cout << longestSubArrayWithLengthK(v, 5);

}