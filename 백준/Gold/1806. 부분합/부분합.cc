#include <iostream>
#include <vector>

#define MIN(x, y) ((x) > (y) ? (y) : (x))

using namespace std;

int main(void) {
	int n, s, left{ -1 }, right{ -1 }, length{ 100001 }, sum{ 0 };
	vector<int> v;

	cin >> n >> s;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	while (true) {
		if (sum < s) {
			if (++right == n)
				break;
			sum += v[right];
		} else {
			length = MIN(length, right - left);
			sum -= v[++left];
		}
	}

	cout << (length == 100001 ? 0 : length) << '\n';

	return 0;
}