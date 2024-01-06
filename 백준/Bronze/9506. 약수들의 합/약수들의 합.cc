#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int n;

		cin >> n;
		if (n == -1)
			break;

		int sum = 0;
		vector<int> v;
		for (int i = 1; i < n && sum <= n; i++) {
			if (n % i == 0) {
				sum += i;
				v.push_back(i);
			}
		}

		cout << n;
		if (sum == n) {
			cout << " = ";
			for (int i = 0; i < v.size() - 1; i++) {
				cout << v[i] << " + ";
			}
			cout << v[v.size() - 1] << '\n';
		} else {
			cout << " is NOT perfect.\n";
		}
	}

	return 0;
}