#include <iostream>

using namespace std;

int main(void) {
	int a, b, v, ans;

	cin >> a >> b >> v;

	v -= a;

	ans = v % (a - b) ? v / (a - b) + 1 : v / (a - b);
	cout << ++ans << endl;
	return 0;
}