#include <iostream>

using namespace std;

int main(void) {
	int a, b, c, money;

	cin >> a >> b >> c;

	if (a == b && b == c) {
		money = 10000 + 1000 * a;
	}
	else if (a == b || b == c || c == a) {
		int same = a;
		if (b == c)
			same = b;
		money = 1000 + 100 * same;
	}
	else {
		if (a >= b && a >= c)
			money = 100 * a;
		else if (b >= a && b >= c)
			money = 100 * b;
		else
			money = 100 * c;
	}

	cout << money << endl;

	return 0;
}