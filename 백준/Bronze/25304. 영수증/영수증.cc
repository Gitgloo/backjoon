#include <iostream>

using namespace std;

int main(void) {
	int x, n, cal;

	cal = 0;
	cin >> x >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		cal += a * b;
	}

	string answer;
	answer = x == cal ? "Yes" : "No";

	cout << answer << endl;

	return 0;
}