#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int count = 0;
	vector<bool> mod(42);

	for (int i = 0; i < 10; i++) {
		int num;
		cin >> num;
		if (!mod[num % 42]) {
			mod[num % 42] = true;
			count++;
		}
	}
	cout << count << endl;

	return 0;
}