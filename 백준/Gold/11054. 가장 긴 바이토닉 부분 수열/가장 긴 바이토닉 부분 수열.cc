#include <iostream>
#define MAX(x, y) ((x) > (y) ? (x) : (y))

using namespace std;

int main(void) {
	int n, ans{ 0 };

	cin >> n;
	int* arr = new int[n + 2]();
	int* dpASC = new int[n + 1]();
	int* dpDESC = new int[n + 2]();

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && max < dpASC[j]) {
				max = dpASC[j];
			}
		}
		dpASC[i] = max + 1;
	}

	for (int i = n; i >= 1; i--) {
		int max = 0;
		for (int j = n + 1; j > i; j--) {
			if (arr[j] < arr[i] && max < dpDESC[j]) {
				max = dpDESC[j];
			}
		}
		dpDESC[i] = max + 1;
	}

	for (int i = 1; i <= n; i++) {
		ans = MAX(ans, dpASC[i] + dpDESC[i]);
	}

	cout << --ans << endl;

	return 0;
}