#include <iostream>

using namespace std;

void mergeSort(int* arr, unsigned int len);
void mergeArray(int* arr1, unsigned int len1, int* arr2, unsigned int len2);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	mergeSort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}

void mergeSort(int* arr, unsigned int len) {
	// 길이가 1이하면 종료
	if (len <= 1) return;

	// 반으로 쪼개서 정렬시키기
	int half = len / 2;
	mergeSort(arr, half);
	mergeSort(arr + half, len - half);

	// 차례대로 쌓기
	mergeArray(arr, half, arr + half, len - half);
}

void mergeArray(int* arr1, unsigned int len1, int* arr2, unsigned int len2) {
	int n = len1 + len2;
	int* temp = new int[n];

	unsigned int left{ 0 }, right{ 0 }, index{ 0 };

	while (left < len1 && right < len2) {
		if (arr1[left] < arr2[right])
			temp[index++] = arr1[left++];
		else
			temp[index++] = arr2[right++];
	}

	while (left < len1) {
		temp[index++] = arr1[left++];
	}

	while (right < len2) {
		temp[index++] = arr2[right++];
	}

	for (int i = 0; i < n; i++) {
		arr1[i] = temp[i];
	}
}