#include <iostream>

using namespace std;

int main(void) {
	int max = 0, index = 0;

	for (int i = 1; i <= 9; i++) {
		int input;
		cin >> input;
		if (input > max) {
			max = input;
			index = i;
		}
	}

	cout << max << endl << index << endl;

	return 0;
}