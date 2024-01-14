#include <iostream>
#include <set>

using namespace std;

int main(void) {
	int n;
	set<string> s;

	s.insert("ChongChong");

	cin >> n;
	while (n--) {
		string a, b;

		cin >> a >> b;
		if (s.find(a) != s.end() || s.find(b) != s.end()) {
			s.insert(a);
			s.insert(b);
		}
	}

	cout << s.size() << endl;

	return 0;
}