#include <iostream>

#define INT_MAX 1000001

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;

	int* arr = new int[n + 2];
	arr[0] = 0;
	for (int i = 1; i < n + 2; i++) {
		*(arr + i) = INT_MAX;
	}

	for (int i = 1; i <= n; i++) {
		int temp;
		int left = 0;
		int right = i;

		cin >> temp;
		
		while (left <= right) {
			int mid = (left + right) / 2;
			
			if (*(arr + mid) < temp) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}

		if (*(arr + left) > temp) {
			*(arr + left) = temp;
		}
	}

	int maxLength = 0;
	while (*(arr + ++maxLength) != INT_MAX);

	cout << maxLength - 1 << endl;

	delete[] arr;
	
	return 0;
}