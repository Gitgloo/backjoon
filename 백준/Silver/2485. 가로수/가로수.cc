#include <iostream>

using namespace std;

int gcd(int a, int b);

int main(void) {
	int n, r, count{ 0 };

	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	r = arr[1] - arr[0];
	for (int i = 1; i < n - 1; i++) {
		r = gcd(r, arr[i + 1] - arr[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		count += (arr[i + 1] - arr[i]) / r - 1;
	}

	cout << count << endl;

	delete[] arr;

	return 0;
}

int gcd(int a, int b) {
	if (b > a)
		return gcd(b, a);

	int r = a % b;

	if (r == 0)
		return b;

	return gcd(b, r);
}