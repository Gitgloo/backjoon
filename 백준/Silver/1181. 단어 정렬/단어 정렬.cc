#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compareString(string a, string b) {
	if (a.length() == b.length()) {
		return a.compare(b) < 0;
	}
	return a.length() < b.length();
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;

	string* arr = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n, compareString);

	cout << arr[0] << '\n';
	for (int i = 1; i < n; i++) {
		if(arr[i - 1] != arr[i])
			cout << arr[i] << '\n';
	}

	delete[] arr;

	return 0;
}