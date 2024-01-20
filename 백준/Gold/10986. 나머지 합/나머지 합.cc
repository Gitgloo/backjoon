#include <iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, before{ 0 };
	long long int count{ 0 };

	cin >> n >> m;

	int* mod = new int[m]();

	for (int i = 1; i <= n; i++) {
		int temp;

		cin >> temp;
		before = (temp + before) % m;
		mod[before]++;
	}


	count += mod[0];
	for (int i = 0; i < m; i++) {
		if (mod[i] > 1) {
			count += (long long int)mod[i] * (mod[i] - 1) / 2;
		}
	}

	cout << count << endl;

	delete[] mod;

	return 0;
}