#include <iostream>
#include <vector>
#include <algorithm>

#define ABS(x) ((x) < 0 ? -(x) : (x))

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, left, right, ans1{ 0 }, ans2{ 1 };
	vector<int> v;

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int min = 2000000001;
	for (int i = 1; i < n; i++) {
		int temp = ABS(v[i - 1] + v[i]);
		if (temp < min) {
			min = temp;
			ans1 = i - 1;
			ans2 = i;
		}
	}

	left = 0;
	right = n - 1;
	while (left < right) {
		int temp = ABS(v[left] + v[right]);

		if (temp < min) {
			ans1 = left;
			ans2 = right;
			min = temp;
		}
		if (ABS(v[left]) < ABS(v[right])) {
			right--;
		} else {
			left++;
		}
	}

	cout << v[ans1] << ' ' << v[ans2] << '\n';

	return 0;
}