#include <iostream>

using namespace std;

int recur(int n, int k);
int recur2(int n, int k);

int main(void) {
	int n, k;

	cin >> n >> k;

	cout << recur(n, k) << endl;
	return 0;
}

int recur(int n, int k) {
	if (n == k) {
		return 1;
	}

	int temp = recur(n - 1, k); 

	long long int temp2 = (temp * (long long int)k) % 1000000007;
	temp2 = (temp2 * recur2(n - k, 1000000007 - 2)) % 1000000007;
	return (temp + temp2) % 1000000007;
}

int recur2(int n, int k) {
	if (k == 0)
		return 1;
	int temp = recur2(n, k / 2);
	temp = (long long int)temp * temp % 1000000007;
	if (k % 2)
		temp = (long long int)temp * n % 1000000007;
	return temp;
}