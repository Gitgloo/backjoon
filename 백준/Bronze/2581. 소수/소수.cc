#include <iostream>

using namespace std;

int main(void) {
	int m, n, sum{0}, min = 10001;

	cin >> m >> n;

	m = m == 1 ? 2 : m;

	for (int i = m; i <= n; i++) {
		bool flag = true;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			if (min == 10001) {
				min = i;
			}
			sum += i;
		}
	}

	if (sum > 0) {
		cout << sum << endl << min << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}