#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	stack<char> s;
	string input, bomb;

	cin >> input >> bomb;

	char lastCh = bomb[bomb.length() - 1];
	for (int i = 0; i < input.length(); i++) {
		s.push(input[i]);

		if (s.top() == lastCh) {
			stack<char> temp;

			for (int i = bomb.length() - 1; i >= 0 && s.size() && bomb[i] == s.top(); i--) {
				temp.push(s.top());
				s.pop();
			}

			if (temp.size() != bomb.length()) {
				while (!temp.empty()) {
					s.push(temp.top());
					temp.pop();
				}
			}
		}
	}

	if (s.empty()) {
		cout << "FRULA\n";

		return 0;
	}

	int index = s.size() - 1;
	char* arr = new char[s.size() + 1];
	*(arr + s.size()) = 0;
	while (!s.empty()) {
		*(arr + index--) = s.top();
		s.pop();
	}

	cout << arr << '\n';

	delete[] arr;

	return 0;
}