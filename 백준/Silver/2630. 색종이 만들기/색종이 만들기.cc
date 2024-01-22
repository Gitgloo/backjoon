#include <iostream>

using namespace std;

typedef struct s_cnt {
	int color[2] = { 0 };
}cnt;
cnt recur(int** arr, int n, int x, int y);

bool isSameColor(int** arr, int n, int x, int y);


int main(void) {
	int n;

	cin >> n;

	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	cnt ans = recur(arr, n, 0, 0);

	cout << ans.color[0] << '\n' << ans.color[1] << '\n';

	return 0;
}

cnt recur(int** arr, int n, int x, int y) {
	cnt ret;

	if (isSameColor(arr, n, x, y)) {
		ret.color[arr[x][y]]++;
	} else {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				cnt result = recur(arr, n / 2, x + n / 2 * i, y + n / 2 * j);

				ret.color[0] += result.color[0];
				ret.color[1] += result.color[1];
			}
		}
	}

	return ret;
}

bool isSameColor(int** arr, int n, int x, int y) {
	int color = arr[x][y];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[x + i][y + j] != color)
				return false;
		}
	}

	return true;
}