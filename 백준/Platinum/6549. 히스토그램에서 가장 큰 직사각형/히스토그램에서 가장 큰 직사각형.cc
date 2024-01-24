#include <iostream>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MAX3(x, y, z) ((x) > (y) ? (x) > (z) ? (x) : (z) : (y) > (z) ? (y) : (z))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

using namespace std;

long long int recur(int* arr, int start, int end);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int n;

		cin >> n;
		if (n == 0)
			break;

		int* arr = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		cout << recur(arr, 0, n - 1) << '\n';

		delete[] arr;
	}

	return 0;
}

long long int recur(int* arr, int start, int end) {
	if (start > end)
		return 0;

	int mid = (start + end) / 2;
	int left = mid - 1, right = mid + 1;
	int minHeight = *(arr + mid);
	long long int maxMidArea = minHeight;

	while ((left >= start || right <= end) && *(arr + left) + *(arr + right)) {
		if (left >= start && (right > end || *(arr + left) > *(arr + right))) {
			minHeight = MIN(minHeight, *(arr + left));

			while (left > start && *(arr + left) <= *(arr + left - 1)) {
				left--;
			}

			long long int area = (long long int)minHeight * (right - left--);
			maxMidArea = MAX(maxMidArea, area);
		} else {
			minHeight = MIN(minHeight, *(arr + right));

			while (right < end && *(arr + right) <= *(arr + right + 1)) {
				right++;
			}

			long long int area = (long long int)minHeight * (right++ - left);
			maxMidArea = MAX(maxMidArea, area);
		}
	}

	long long int maxLeftArea = recur(arr, start, mid - 1);
	long long int maxRightArea = recur(arr, mid + 1, end);

	return MAX3(maxMidArea, maxLeftArea, maxRightArea);
}