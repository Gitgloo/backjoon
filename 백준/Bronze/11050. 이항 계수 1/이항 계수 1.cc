#include <iostream>

using namespace std;

int main(void) {
	int n, k, ans{ 1 };

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		ans *= i;
	}

	for (int i = 1; i <= k; i++) {
		ans /= i;
	}

	for (int i = 1; i <= n - k; i++) {
		ans /= i;
	}

	cout << ans << endl;

	return 0;
}