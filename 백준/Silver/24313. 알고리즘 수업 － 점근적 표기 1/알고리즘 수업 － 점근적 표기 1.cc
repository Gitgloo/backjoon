#include <iostream>

using namespace std;

int main(void) {
	int a1, a2, c, n0, ans{0};

	cin >> a1 >> a2 >> c >> n0;

	int line = c - a1;

	if (line > 0 && (double)a2 / (c - a1) <= n0) {
		ans = 1;
	} else if (line == 0 && a2 <= 0) {
		ans = 1;
	}

	cout << ans << endl;

	return 0;
}