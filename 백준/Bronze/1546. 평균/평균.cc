#include <iostream>

using namespace std;

int main(void) {
	int n, m = 0, sum = 0;

	cin >> n;
	for(int i = 0; i < n; i++) {
		int score;
		cin >> score;
		sum += score;
		if (score > m)
			m = score;
	}

	cout << 100.0 * sum / m / n << endl;

	return 0;
}