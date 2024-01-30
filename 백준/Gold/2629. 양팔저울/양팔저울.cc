#include <iostream>

using namespace std;

int main(void) {
	int n, m, arr[30], sum{ 0 };

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> *(arr + i);
		sum += *(arr + i);
	}

	bool* dp = new bool[sum + 1]();
	*dp = true;

	for (int i = 0; i < n; i++) {
		for (int j = sum; j >= 0; j--) {
			if (*(dp + j)) {
				*(dp + j + *(arr + i)) = true;
			}
		}
	}

	cin >> m;
	while (m--) {
		int temp;

		cin >> temp;
		bool result = false;
		for (int i = 0; i <= sum - temp; i++) {
			if (*(dp + i) && *(dp + i + temp)) {
				result = true;
				break;
			}
		}

		if (result)
			cout << "Y ";
		else
			cout << "N ";
	}
	cout << endl;

	delete[] dp;
	return 0;
}