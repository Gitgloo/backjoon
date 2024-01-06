#include <iostream>

using namespace std;

int main(void) {
	int a, b, c;

	cin >> a >> b >> c;

	if (a + b + c != 180) {
		cout << "Error" << endl;
	} else {
		if (a == 60 && b == 60) {
			cout << "Equilateral" << endl;
		} else if (a == b || b == c || c == a) {
			cout << "Isosceles" << endl;
		} else {
			cout << "Scalene" << endl;
		}
	}

	return 0;
}