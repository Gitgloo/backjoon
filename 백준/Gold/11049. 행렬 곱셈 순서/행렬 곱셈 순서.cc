#include <iostream>

#define MIN(x, y) ((x) > (y) ? (y) : (x))

using namespace std;

struct matrix {
	int r, c;
};

int main(void) {
	int n;

	cin >> n;
	matrix* arr = new matrix[n];


	for (int i = 0; i < n; i++) {
		cin >> (arr + i)->r >> (arr + i)->c;
	}

	int** dp = new int* [n];
	for (int i = 0; i < n; i++) {
		*(dp + i) = new int[n];
		*(*(dp + i) + i) = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			int min = 2147483647;
			for (int k = i; k > j; k--) {
				min = MIN(min, *(*(dp + j) + k - 1) + *(*(dp + k) + i) + (arr + j)->r * (arr + k)->r * (arr + i)->c);
			}
			*(*(dp + j) + i) = min;
		}
	}

	cout << *(*dp + n - 1) << endl;

	for (int i = 0; i < n; i++) {
		delete[] * (dp + i);
	}

	delete[] dp;

	return 0;
}