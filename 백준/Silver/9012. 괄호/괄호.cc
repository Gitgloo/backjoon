#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	int T;

	cin >> T;
	while (T--) {
		int count = 0;
		string temp, answer{ "YES" };
		stack<char> s;

		cin >> temp;
		for (int i = 0; i < temp.length(); i++) {
			s.push(temp[i]);
		}

		while (!s.empty()) {
			if (s.top() == '(') {
				if (count > 0) {
					count--;
				} else {
					answer = "NO";
					break;
				}
			} else {
				count++;
			}
			s.pop();
		}

		if (count > 0) {
			answer = "NO";
		}

		cout << answer << endl;
	}

	return 0;
}