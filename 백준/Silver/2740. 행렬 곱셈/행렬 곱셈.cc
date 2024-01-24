#include <iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;

	cin >> n >> m;
	int** arrA = new int* [n];
	for (int i = 0; i < n; i++) {
		arrA[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> arrA[i][j];
		}
	}

	cin >> m >> k;
	int** arrB = new int* [m];
	for (int i = 0; i < m; i++) {
		arrB[i] = new int[k];
		for (int j = 0; j < k; j++) {
			cin >> arrB[i][j];
		}
	}

	int** result = new int* [n];
	for (int i = 0; i < n; i++) {
		result[i] = new int[k]();
		for (int j = 0; j < k; j++) {
			for (int l = 0; l < m; l++) {
				result[i][j] += arrA[i][l] * arrB[l][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 0; i < n; i++) {
		delete[] arrA[i];
	}
	delete[] arrA;

	for (int i = 0; i < m; i++) {
		delete[] arrB[i];
	}
	delete[] arrB;

	for (int i = 0; i < n; i++) {
		delete[] result[i];
	}
	delete[] result;

	return 0;
}