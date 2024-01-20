#include <iostream>

using namespace std;

long long int recur(int* arr, int left, int right, int m);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	int* arr = new int[n + 1];

	arr[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] = (arr[i] + arr[i - 1]) % m;
	}

	cout << recur(arr, 1, n, m) << '\n';

	return 0;
}

long long int recur(int* arr, int left, int right, int m) {
	if (left > right)
		return 0;

	int mid = (left + right) / 2;
	long long int count = 0;
	int* lCount = new int[m]();
	int* rCount = new int[m]();

	for (int i = left; i <= mid; i++) {
		lCount[(arr[mid] - arr[i - 1] + m) % m]++;
	}

	for (int i = mid + 1; i <= right; i++) {
		rCount[(arr[i] - arr[mid] + m) % m]++;
	}

	count += (long long int)lCount[0] * (rCount[0] + 1);
	for (int i = 1; i < m; i++) {
		count += (long long int)lCount[i] * (rCount[m - i]);
	}

	delete[] lCount;
	delete[] rCount;

	return count + recur(arr, left, mid - 1, m) + recur(arr, mid + 1, right, m);
}