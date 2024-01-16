#include <iostream>

using namespace std;

int k = 0;
int cnt = 0;

bool merge(int* arr, int p, int q, int r);

bool mergeSort(int* arr, int p, int r) {
	if (p >= r)
		return false;

	int q = (p + r) / 2;
	if (mergeSort(arr, p, q))
		return true;
	if (mergeSort(arr, q + 1, r))
		return true;
	return merge(arr, p, q, r);
}

bool merge(int* arr, int p, int q, int r) {
	int i = p, j = q + 1, t = 0, *tmp = new int[r - p + 1];

	while (i <= q && j <= r) {
		if (arr[i] <= arr[j])
			tmp[t++] = arr[i++];
		else
			tmp[t++] = arr[j++];
	}

	while(i <= q)
		tmp[t++] = arr[i++];

	while (j <= r)
		tmp[t++] = arr[j++];

	i = p;
	t = 0;
	while (i <= r){
		if (++cnt == k) {
			cout << tmp[t] << endl;

			return true;
		}
		arr[i++] = tmp[t++];
	}
	delete[] tmp;

	return false;
}


int main(void) {
	int n;

	cin >> n >> k;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	if (!mergeSort(arr, 0, n - 1))
		cout << -1 << endl;
	return 0;
}