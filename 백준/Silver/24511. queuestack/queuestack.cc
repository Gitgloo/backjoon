#include <iostream>
#include <deque>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	deque<int> dq;

	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		int temp;

		cin >> temp;
		if (arr[i])
			continue;

		dq.push_back(temp);
	}


	cin >> m;
	for (int i = 0; i < m; i++) {
		int temp;

		cin >> temp;
		dq.push_front(temp);
		cout << dq.back() << ' ';
		dq.pop_back();
	}
	cout << endl;

	delete[] arr;

	return 0;
}