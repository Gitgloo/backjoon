#include <iostream>

#define MIN2(x, y) ((x) > (y) ? (y) : (x))
#define MIN3(x, y, z) ((x) > (y) ? (y) > (z) ? (z) : (y) : (x) > (z) ? (z) : (x))

using namespace std;

int main(void) {
	int n;

	cin >> n;
	int** dp = new int*[n];
	for (int i = 0; i < n; i++) {
		dp[i] = new int[3];
	}

	cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> dp[i][j];

			dp[i][j] += MIN2(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
		}
	}

	cout << MIN3(dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]) << endl;

	return 0;
}