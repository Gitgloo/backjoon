#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	vector<bool> v(31);

	for (int i = 0; i < 28; i++) {
		int num;
		cin >> num;

		v[num] = true;
	}

	for (int i = 1; i < v.size(); i++) {
		if (!v[i])
			cout << i << endl;
	}
	return 0;
}