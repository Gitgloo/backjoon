#include <iostream>

using namespace std;

int main(void) {
	const int n = 5;
	int arr[n];
	int sum = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				arr[j] += arr[j + 1];
				arr[j + 1] = arr[j] - arr[j + 1];
				arr[j] -= arr[j + 1];
			}
		}
	}

	cout << sum / 5 << endl << arr[n / 2] << endl;

	return 0;
}