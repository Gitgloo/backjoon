#include <iostream>

using namespace std;

void recur(long long int n, int** ret);
void multiArr(int** arrA, int** arrB, int** ret);
void copyArr(int** arr, int** ret);
int** createArr();
void deleteArr(int** arr);

int** base;

int main(void) {
	long long int n;
	int** arr = createArr();

	base = createArr();
	base[0][0] = 1;
	base[0][1] = 1;
	base[1][0] = 1;
	base[1][1] = 0;
	
	cin >> n;
	
	if (n <= 1) {
		cout << n << endl;
	} else {
		recur(n - 1, arr);
		cout << arr[0][0] << endl;
	}

	deleteArr(arr);
	deleteArr(base);

	return 0;
}

void recur(long long int n, int** ret) {
	if (n == 1) {
		copyArr(base, ret);
		return;
	}

	int** temp = createArr();

	recur(n / 2, temp);
	multiArr(temp, temp, ret);

	if (n % 2) {
		int** temp2 = createArr();

		copyArr(ret, temp2);
		multiArr(base, temp2, ret);
		deleteArr(temp2);
	}

	deleteArr(temp);
}

void multiArr(int** arrA, int** arrB, int** ret) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			long long int sum = 0;
			for (int k = 0; k < 2; k++) {
				sum = (sum + (long long int)arrA[i][k] * arrB[k][j]) % 1000000007;
			}
			ret[i][j] = sum;
		}
	}
}

void copyArr(int** arr, int** ret) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			ret[i][j] = arr[i][j];
		}
	}
}

int** createArr() {
	int** arr = new int* [2];
	for (int i = 0; i < 2; i++) {
		arr[i] = new int[2];
	}
	return arr;
}

void deleteArr(int** arr) {
	for (int i = 0; i < 2; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}