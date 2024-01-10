#include <iostream>
#include <set>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, count{ 0 };
	set<int> s;

	cin >> a >> b;
	for(int i = 0; i < a; i++) {
		int temp;

		cin >> temp;
		s.insert(temp);
	}

	for (int i = 0; i < b; i++) {
		int temp;

		cin >> temp;
		if (s.find(temp) != s.end()) {
			count++;
		}
	}

	cout << a + b - 2 * count << endl;

	return 0;
}