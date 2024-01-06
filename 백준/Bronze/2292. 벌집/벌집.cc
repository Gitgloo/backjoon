#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int n, answer = 0, max = 0;

	cin >> n;

	n -= 1;
	while (true) {
		max += 6 * answer++;
		if (n <= max) {
			break;
		}
	}

	cout << answer;

	return 0;
}