#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	cin.tie(NULL);

	int k, sum{ 0 };
	stack<int> s;

	cin >> k;
	while (k--) {
		int temp;

		cin >> temp;
		if (temp == 0)
			s.pop();
		else
			s.push(temp);
	}

	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}

	cout << sum << endl;

	return 0;
}