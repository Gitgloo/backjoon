#include <iostream>
#include <cmath>

using namespace std;

void space(int n);
void recur(int n);

int main(void) {
	while (true) {
		int n;

		cin >> n;

		if (cin.eof())
			break;

		recur(n);
		cout << '\n';
	}
	return 0;
}

void space(int n) {
	int repeat = pow(3, n);

	while (repeat--) {
		cout << ' ';
	}
}

void recur(int n) {
	if (n == 0) {
		cout << '-';
		return;
	}

	recur(n - 1);
	space(n - 1);
	recur(n - 1);
}