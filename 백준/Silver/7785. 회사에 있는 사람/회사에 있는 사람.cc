#include <iostream>
#include <set>

using namespace std;

struct myOrder {
	bool operator() (const string& a, const string& b) const{
		return a.compare(b) > 0;
	}
};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	set<string, myOrder> s;

	cin >> n;
	while (n--) {
		string name;
		string option;

		cin >> name >> option;
		if (option[0] == 'e') {
			s.insert(name);
		} else {
			s.erase(name);
		}
	}

	for (set<string>::iterator iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << '\n';
	}

	return 0;
}