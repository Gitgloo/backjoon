#include <iostream>

using namespace std;

int main(void) {
	int xSave[1001] = { 0 };
	int ySave[1001] = { 0 };
	int tempX[3];
	int tempY[3];

	for (int i = 0; i < 3; i++) {
		int x, y;
		cin >> x >> y;

		xSave[x]++;
		ySave[y]++;
		tempX[i] = x;
		tempY[i] = y;
	}

	for (int i = 0; i < 3; i++) {
		if (xSave[tempX[i]] == 1) {
			cout << tempX[i] << ' ';
			break;
		}
	}

	for (int i = 0; i < 3; i++) {
		if (ySave[tempY[i]] == 1) {
			cout << tempY[i] << endl;
			break;
		}
	}
	return 0;
}