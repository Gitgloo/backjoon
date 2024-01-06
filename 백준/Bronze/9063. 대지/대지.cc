#include <iostream>

using namespace std;

int main(void) {
	int n, minX{ 10001 }, minY{ 10001 }, maxX{ -10001 }, maxY{ -10001 };

	cin >> n;
	while (n--) {
		int x, y;

		cin >> x >> y;
		if (x < minX) {
			minX = x;
		}
		if (x > maxX) {
			maxX = x;
		}

		if (y < minY) {
			minY = y;
		}
		if (y > maxY) {
			maxY = y;
		}
	}

	cout << (maxX - minX) * (maxY - minY) << endl;

	return 0;
}