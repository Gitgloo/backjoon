#include <iostream>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

using namespace std;

int main(void) {
	string a, b;

	cin >> a >> b;
	
	int** dp = new int* [a.length() + 1];
	for (int i = 0; i <= a.length(); i++) {
		dp[i] = new int[b.length() + 1]();
	}

	for (int i = 0; i < a.length(); i++) {
		for (int j = 0; j < b.length(); j++) {
			if (a[i] == b[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			} else {
				dp[i + 1][j + 1] = MAX(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}

	cout << dp[a.length()][b.length()] << endl;

	return 0;
}