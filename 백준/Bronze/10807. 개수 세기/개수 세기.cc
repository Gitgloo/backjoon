#include <iostream>
#include <memory.h>	// 백준에서 memset 사용하려면 필요

using namespace std;

int main(void) {
	int n, find;
	int arr[201];
	// 배열 초기화
	memset(arr, 0, sizeof(arr));

	cin >> n;
	while (n--) {
		int input;
		cin >> input;
		arr[input + 100]++;
	}

	cin >> find;

	cout << arr[find + 100] << endl;
	return 0;
}