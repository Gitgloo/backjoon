#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n, b;
	vector<char> v;

	cin >> n >> b;
	while (n) {
		int mod = n % b;
		if (mod < 10)
			v.push_back(mod + '0');
		else
			v.push_back(mod - 10 + 'A');
		n /= b;
	}
	
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i];
	}
	cout << endl;

	return 0;
}