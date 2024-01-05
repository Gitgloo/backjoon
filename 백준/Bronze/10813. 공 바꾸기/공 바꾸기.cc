#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n, m;

	cin >> n >> m;
	vector<int> v(n + 1);
	
	int* vecPtr1 = &v[0];
	for (size_t i = 0; i < v.size(); i++) {
		*(vecPtr1 + i) = i;
	}

	while (m--) {
		int i, j;
		cin >> i >> j;
		if (i == j)
			continue;
		v[i] += v[j];
		v[j] = v[i] - v[j];
		v[i] -= v[j];
	}

	int* vecPtr2 = &v[0];
	for (size_t i = 1; i < v.size(); i++) {
		cout << *(vecPtr2 + i) << ' ';
	}
	cout << endl;

	return 0;
}