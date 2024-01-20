#include <iostream>

#define MIN(x, y) ((x) > (y) ? (y) : (x))

using namespace std;

int main(void) {
	int n, m, k, min{ 4000000 };

	cin >> n >> m >> k;
	int** arr = new int* [n + 1];
	for (int i = 0; i <= n; i++) {
		arr[i] = new int[m + 1];
		arr[i][0] = 0;
	}

	for (int i = 1; i <= n; i++) {
		string temp;

		cin >> temp;
		for (int j = 1; j <= temp.length(); j++) {
			if((i + j) % 2)
				arr[i][j] = temp[j - 1] == 'B';
			else
				arr[i][j] = temp[j - 1] == 'W';

			arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}
	}

	for (int i = k; i <= n; i++) {
		for (int j = k; j <= m; j++) {
			int temp = arr[i][j] - arr[i - k][j] - arr[i][j - k] + arr[i - k][j - k];

			temp = MIN(temp, k * k - temp);
			min = MIN(min, temp);
		}
	}

	cout << min << '\n';

	for (int i = 0; i <= n; i++) {
		delete[] arr[i];
	}

	delete[] arr;

	return 0;
}