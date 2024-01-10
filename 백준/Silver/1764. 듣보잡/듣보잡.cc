#include <iostream>
#include <set>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	set<string> s1, s2;

	cin >> n >> m;
	while (n--) {
		string name;

		cin >> name;
		s1.insert(name);
	}

	while (m--) {
		string name;

		cin >> name;
		if (s1.find(name) != s1.end()) {
			s2.insert(name);
		}
	}

	cout << s2.size() << '\n';
	for (set<string>::iterator iter = s2.begin(); iter != s2.end(); iter++) {
		cout << *iter << '\n';
	}

	return 0;
}