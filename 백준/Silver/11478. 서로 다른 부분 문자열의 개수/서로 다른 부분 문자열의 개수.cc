#include <iostream>
#include <set>

using namespace std;

int main(void) {
	string str;
	set<string> s;

	cin >> str;
	for (int i = 1; i <= str.length(); i++) {
		for (int j = 0; j + i <= str.length(); j++) {
			s.insert(str.substr(j, i));
		}
	}

	cout << s.size() << endl;

	return 0;
}