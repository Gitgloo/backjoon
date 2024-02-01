#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, count[1000001] = { 0 };
	stack<int> s;

	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> *(arr + i);
		(*(count + *(arr + i)))++;
	}

	for (int i = n - 1; i >= 0; i--) {
		int nowValue = *(arr + i);

		while (s.size() && *(count + s.top()) <= *(count + nowValue)) {
			s.pop();
		}

		if (s.empty()) {
			*(arr + i) = -1;
		} else {
			*(arr + i) = s.top();
		}
		s.push(nowValue);
	}

	for (int i = 0; i < n; i++) {
		cout << *(arr + i) << ' ';
	}
	cout << '\n';

	delete[] arr;

	return 0;
}