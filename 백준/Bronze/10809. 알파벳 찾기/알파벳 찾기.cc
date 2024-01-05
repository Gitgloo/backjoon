#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	string str;
	vector<int> answer('z' + 1, -1);

	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		char ch = str[i];
		if (answer[ch] == -1)
			answer[ch] = i;
	}

	for (int i = 'a'; i <= 'z'; i++) {
		cout << answer[i] << ' ';
	}
	cout << endl;

	return 0;
}