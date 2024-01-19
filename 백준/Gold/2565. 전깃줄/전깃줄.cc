#include <iostream>
#define MAX(x, y) ((x) > (y) ? (x) : (y))

using namespace std;

int main(void) {
	int n, ans{ 0 }, arr[501]{ 0 }, dp[501]{ 0 };

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;

		cin >> a >> b;
		arr[a] = b;
	}

	for (int i = 1; i <= 500; i++) {
		if (!arr[i])
			continue;

		int max = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && max < dp[j]) {
				max = dp[j];
			}
		}
		dp[i] = max + 1;
	}

	for (int i = 1; i <= 500; i++) {
		ans = MAX(ans, dp[i]);
	}

	cout << n - ans << endl;

	return 0;
}