#include <iostream>

using namespace std;

int main(void) {
	int n, m, memory[100], cost[100], dp[10001] = {}, sum{ 0 };

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> *(memory + i);
	}

	for (int i = 0; i < n; i++) {
		cin >> *(cost + i);
		sum += *(cost + i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = sum; j >= *(cost + i); j--) {
			int temp = *(dp + j - *(cost + i)) - *(memory + i);

			if (*(dp + j) > temp)
				*(dp + j) = temp;
		}
	}

	for (int i = 0; i <= sum; i++) {
		if (-*(dp + i) >= m) {
			cout << i << endl;
			break;
		}
	}

	return 0;
}