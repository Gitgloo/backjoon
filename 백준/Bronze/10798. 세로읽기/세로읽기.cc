#include <iostream>

using namespace std;

int main(void) {
	char arr[5][15] = {0};

	for (int i = 0; i < 5; i++) {
		string str;
		
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			arr[i][j] = str[j];
		}
	}

	for (int j = 0; j < 15; j++) {
		for (int i = 0; i < 5; i++) {
			if(arr[i][j])
				cout << arr[i][j];
		}
	}
	cout << endl;

	return 0;
}