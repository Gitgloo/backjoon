#include <iostream>
#include <set>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	set<int> s;

	cin >> n;
	while (n--) {
		int temp;
		cin >> temp;
		s.insert(temp);
	}

	cin >> m;
	while (m--) {
		int temp;
		cin >> temp;
		cout << (s.find(temp) != s.end()) << ' ';
	}


	return 0;
}