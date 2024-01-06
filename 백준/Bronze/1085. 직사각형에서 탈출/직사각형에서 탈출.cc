#include <iostream>

using namespace std;

int main(void) {
	int x, y, w, h, min{1000};

	cin >> x >> y >> w >> h;

	if (x < min)
		min = x;
	if (w - x < min)
		min = w - x;
	if (y < min)
		min = y;
	if (h - y < min)
		min = h - y;

	cout << min << endl;

	return 0;
}