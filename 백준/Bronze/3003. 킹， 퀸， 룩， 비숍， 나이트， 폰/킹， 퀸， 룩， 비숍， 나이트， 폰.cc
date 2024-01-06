#include <iostream>

using namespace std;

int main(void) {
	int correct[6] = { 1, 1, 2, 2, 2, 8 };

	for (int i = 0; i < 6; i++) {
		int temp;
		cin >> temp;
		cout << correct[i] - temp << ' ';
	}
	cout << endl;

	return 0;
}