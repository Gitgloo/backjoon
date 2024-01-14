#include <iostream>
#include <set>

using namespace std;

int main(void) {
	int n, count{ 0 };
	set<string> s;

	cin >> n;
	while (n--) {
		string str;

		cin >> str;
		if (str == "ENTER") {
			s.clear();
		} else if(s.find(str) == s.end()) {
			s.insert(str);
			count++;
		}
	}

	cout << count << endl;

	return 0;
}