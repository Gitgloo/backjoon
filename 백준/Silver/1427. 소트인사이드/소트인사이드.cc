#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	string n;

	cin >> n;

	char* arr = new char[n.length()];

	for (int i = 0; i < n.length(); i++) {
		arr[i] = n[i];
	}

	sort(arr, arr + n.length());

	for (int i = n.length() - 1; i >= 0; i--) {
		cout << arr[i];
	}
	cout << endl;

	return 0;
}