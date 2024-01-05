#include <iostream>

using namespace std;

int main(void) {
	int t;

	cin >> t;
	while(t--) {
		int r;
		string str;
		
		cin >> r >> str;
		for (size_t i = 0; i < str.length(); i++) {
			for (int j = 0; j < r; j++) {
				cout << str[i];
			}
		}
		cout << endl;
	}

	return 0;
}