#include <iostream>

using namespace std;

int main(void) {
	int row = 0, col = 0, max = -1;

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			int temp;

			cin >> temp;
			if (temp > max) {
				max = temp;
				row = i;
				col = j;
			}
		}
	}

	cout << max << endl << row << ' ' << col << endl;
	return 0;
}