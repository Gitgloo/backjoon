#include <iostream>

using namespace std;

string recur(char** arr, int n, int x, int y);

bool isSameColor(char** arr, int n, int x, int y);

int main(void) {
	int n;

	cin >> n;

	char** arr = new char* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new char[n + 1];
		cin >> arr[i];
	}

	cout << recur(arr, n, 0, 0) << endl;

	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}

string recur(char** arr, int n, int x, int y) {
	string result;

	if (isSameColor(arr, n, x, y)) {
		result.push_back(arr[x][y]);
		return result;
	}

	result.push_back('(');

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			result += recur(arr, n / 2, x + n / 2 * i, y + n / 2 * j);
		}
	}

	return result + ")";
}

bool isSameColor(char** arr, int n, int x, int y) {
	char color = arr[x][y];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[x + i][y + j] != color)
				return false;
		}
	}

	return true;
}