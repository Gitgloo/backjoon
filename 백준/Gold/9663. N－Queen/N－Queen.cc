#include <iostream>
#define ABS(x) ((x) < 0 ? -(x) : (x))

using namespace std;

int recur(int n, int* arr, int index);
bool isPossible(int n, int* arr, int index, int now);

int main(void) {
	int n;

	cin >> n;
	int* arr = new int[n];
	cout << recur(n, arr, 0) << endl;

	delete[] arr;

	return 0;
}

int recur(int n, int* arr, int index) {
	// 다 채워넣었으면 횟수 1로 리턴
	if (index == n)
		return 1;

	int count = 0;
	for (int i = 0; i < n; i++) {
		// 가능한지 체크하고 가능하면 재귀
		if (isPossible(n, arr, index, i)) {
			arr[index] = i;
			count += recur(n, arr, index + 1);
		}
	}

	return count;
}

bool isPossible(int n, int* arr, int index, int now) {
	for (int i = 0; i < index; i++) {
		if (arr[i] == now || ABS(arr[i] - now) == ABS(i - index))
			return false;
	}

	return true;
}