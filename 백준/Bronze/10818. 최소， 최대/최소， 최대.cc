#include <iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, min, max;
	min = 1000000;
	max = -1000000;

	cin >> n;

	while (n--) {
		int num;
		cin >> num;

		if (num < min)
			min = num;
		if (num > max)
			max = num;
	}

	cout << min << ' ' << max << endl;

	return 0;
}