#include <iostream>

using namespace std;

int main(void) {
	int x, max{1}, i{ 1 };

	cin >> x;
	while (true) {
		if (x <= max) {
			break;
		}
		max += ++i;
	}

	x -= i * (i - 1) / 2;

	if (i % 2) {
		cout << i - x + 1 << '/' << x << endl;
	} else {
		cout << x << '/' << i - x + 1 << endl;
	}

	return 0;
}