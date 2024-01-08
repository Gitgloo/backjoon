#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n, k;

	cin >> n >> k;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	
	cout << v[n - k] << endl;

	return 0;
}