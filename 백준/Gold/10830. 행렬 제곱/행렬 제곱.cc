#include <iostream>

using namespace std;

void recur(int n, int** arr, long long int b, int** ret);
void multiArr(int n, int** arrA, int** arrB, int** ret);
void copyArr(int n, int** arr, int** ret);
int** createArr(int n);
void deleteArr(int n, int** arr);
void printArr(int n, int** arr);
void getArr(int n, int** arr);

int main(void) {
	int n;
	long long int b;

	cin >> n >> b;
	int** arr = createArr(n);
	int** ret = createArr(n);

	getArr(n, arr);
	recur(n, arr, b, ret);
	printArr(n, ret);

	deleteArr(n, arr);
	deleteArr(n, ret);

	return 0;
}

void recur(int n, int** arr, long long int b, int** ret) {
	if (b == 1) {
		copyArr(n, arr, ret);
		return;
	}

	int** temp = createArr(n);

	recur(n, arr, b / 2, temp);
	multiArr(n, temp, temp, ret);

	if (b % 2) {
		int** temp2 = createArr(n);

		copyArr(n, ret, temp2);
		multiArr(n, arr, temp2, ret);
		deleteArr(n, temp2);
	}

	deleteArr(n, temp);
}

void multiArr(int n, int** arrA, int** arrB, int** ret) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int sum = 0;
			for (int k = 0; k < n; k++) {
				sum += arrA[i][k] * arrB[k][j];
			}
			ret[i][j] = sum % 1000;
		}
	}
}

void copyArr(int n, int** arr, int** ret) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ret[i][j] = arr[i][j] % 1000;
		}
	}
}

int** createArr(int n) {
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}
	return arr;
}

void deleteArr(int n, int** arr) {
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

void printArr(int n, int** arr) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}

void getArr(int n, int** arr) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}