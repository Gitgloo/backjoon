#include <iostream>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

using namespace std;

void recur(int n, int* numbers, int* arr, int index, int sum, int* max, int* min);

int main(void) {
	int n, arr[4], max{ -1000000000 }, min{ 1000000000 };

	cin >> n;
	int* numbers = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}

	recur(n, numbers, arr, 1, numbers[0], &max, &min);

	delete[] numbers;

	cout << max << endl << min << endl;

	return 0;
}

void recur(int n, int* numbers, int* arr, int index, int sum, int* max, int* min) {
	if (index == n) {
		*max = MAX(*max, sum);
		*min = MIN(*min, sum);
		return;
	}

	if (arr[0]) {
		arr[0]--;
		recur(n, numbers, arr, index + 1, sum + numbers[index], max, min);
		arr[0]++;
	}

	if (arr[1]) {
		arr[1]--;
		recur(n, numbers, arr, index + 1, sum - numbers[index], max, min);
		arr[1]++;
	}

	if (arr[2]) {
		arr[2]--;
		recur(n, numbers, arr, index + 1, sum * numbers[index], max, min);
		arr[2]++;
	}

	if (arr[3]) {
		arr[3]--;
		recur(n, numbers, arr, index + 1, sum / numbers[index], max, min);
		arr[3]++;
	}
}