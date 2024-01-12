#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	while (true) {
		string str, answer{ "yes" };
		stack<char> s;

		getline(cin, str, '\n');

		if (str[0] == '.')
			break;

		for (int i = 0; i < str.length(); i++) {
			char ch = str[i];
			if (ch == '(' || ch == '[') {
				s.push(ch);
			} else if (ch == ')') {
				if (!s.empty() && s.top() == '(') {
					s.pop();
				} else {
					answer = "no";
					break;
				}
			} else if (ch == ']') {
				if (!s.empty() && s.top() == '[') {
					s.pop();
				}
				else {
					answer = "no";
					break;
				}
			}
		}

		if (!s.empty())
			answer = "no";

		cout << answer << endl;
	}

	return 0;
}