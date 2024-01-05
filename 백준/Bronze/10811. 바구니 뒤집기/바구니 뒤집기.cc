#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n, m;

	cin >> n >> m;
	vector<int> v(n + 1);

	for (size_t i = 1; i < v.size(); i++) {
		v[i] = i;
	}

	while (m--) {
		size_t i, j;

		cin >> i >> j;
		for (size_t k = 0; k < (j - i + 1) / 2; k++) {
			v[i + k] += v[j - k];
			v[j - k] = v[i + k] - v[j - k];
			v[i + k] -= v[j - k];
		}
	}

	for (size_t i = 1; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	cout << endl;

	return 0;
}