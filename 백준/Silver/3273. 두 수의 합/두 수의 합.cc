#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, x, count{ 0 }, left, right;
	vector<int> v;

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> x;

	left = 0, right = n - 1;
	sort(v.begin(), v.end());
	while (left < right) {
		int temp = v[left] + v[right];
		if (temp == x) {
			count++;
			left++;
			right--;
		} else if (temp < x) {
			left++;
		} else {
			right--;
		}
	}

	cout << count << '\n';

	return 0;
}