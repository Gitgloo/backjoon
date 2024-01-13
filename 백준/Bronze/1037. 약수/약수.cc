#include <iostream>
#include <algorithm>

using namespace std;

long long int gcd(long long int a, long long int b);

int main(void) {
	int n;
	long long int ans{ 1 };

	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		ans = ans * arr[i] / gcd(ans, arr[i]);
	}

	if (ans == arr[n - 1]) {
		ans *= arr[0];
	}

	cout << ans << endl;

	delete[] arr;

	return 0;
}

long long int gcd(long long int a, long long int b) {
	if (b > a)
		gcd(b, a);

	long long int r = a % b;

	if (r == 0)
		return b;

	return gcd(b, r);
}