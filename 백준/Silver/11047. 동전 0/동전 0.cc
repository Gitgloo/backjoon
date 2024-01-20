#include <iostream>

using namespace std;

int main(void) {
	int n, k, count{ 0 };

	cin >> n >> k;

	int* coins = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		count += k / coins[i];
		k %= coins[i];
	}

	cout << count << endl;

	delete[] coins;

	return 0;
}