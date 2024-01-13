#include <iostream>

using namespace std;

int main(void) {
	int T, arr[30][30];

	for (int i = 0; i < 30; i++) {
		arr[i][0] = 1;
		arr[i][i] = 1;
	}

	for (int i = 2; i < 30; i++) {
		for (int j = 1; j < i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	cin >> T;
	while (T--) {
		int n, m;

		cin >> n >> m;
		cout << arr[m][n] << endl;
	}

	return 0;
}