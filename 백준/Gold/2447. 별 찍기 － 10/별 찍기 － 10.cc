#include <iostream>

using namespace std;

void blank(char** arr, int n, int x, int y);
void recur(char** arr, int n, int x, int y);

int main(void) {
	int n;
	
	cin >> n;
	char** arr = new char* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new char[n];
	}

	recur(arr, n, 0, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}

	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}

	delete[] arr;

	return 0;
}

void blank(char** arr, int n, int x, int y) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[x + i][y + j] = ' ';
		}
	}
}

void recur(char** arr, int n, int x, int y) {
	if (n == 1) {
		arr[x][y] = '*';
		return;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)
				blank(arr, n / 3, x + n / 3, y + n / 3);
			else
				recur(arr, n / 3, x + i * n / 3, y + j * n / 3);
		}
	}
}