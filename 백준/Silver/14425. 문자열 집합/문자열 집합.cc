#include <iostream>
#include <set>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, count{ 0 };
	set<string> s;

	cin >> n >> m;

	while (n--) {
		string temp;

		cin >> temp;
		s.insert(temp);
	}

	while (m--) {
		string temp;

		cin >> temp;
		if (s.find(temp) != s.end())
			count++;
	}

	cout << count << endl;

	return 0;
}