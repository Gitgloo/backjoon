#include <iostream>

using namespace std;

void recur(int n, int from, int to);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;
	cout << (2 << n - 1) - 1 << '\n';
	recur(n, 1, 3);
	return 0;
}

void recur(int n, int from, int to) {
	if (n == 0)
		return;

	recur(n - 1, from, 6 - from - to);
	cout << from << ' ' << to << '\n';
	recur(n - 1, 6 - from - to, to);
}