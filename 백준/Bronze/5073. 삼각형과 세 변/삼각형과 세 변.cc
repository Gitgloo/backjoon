#include <iostream>

using namespace std;

int main(void) {

	while(true) {
		int a, b, c;

		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0) {
			break;
		}

		if (a + b <= c || b + c <= a || c + a <= b) {
			cout << "Invalid" << endl;
		} else if (a == b && b == c && c == a) {
			cout << "Equilateral" << endl;
		} else if (a == b || b == c || c == a) {
			cout << "Isosceles" << endl;
		} else {
			cout << "Scalene" << endl;
		}
	}

	return 0;
}