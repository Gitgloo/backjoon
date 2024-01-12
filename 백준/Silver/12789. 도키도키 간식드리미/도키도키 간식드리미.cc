#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	int n, order{ 1 };
	stack<int> s;

	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int index = 0;
	while (index < n) {
		if (arr[index] == order) {
			index++;
			order++;
		}

		while (!s.empty()) {
			if (s.top() == order) {
				s.pop();
				order++;
			} else {
				break;
			}
		}

		while (index < n && arr[index] != order) {
			s.push(arr[index++]);
		}
	}

	if (order > n)
		cout << "Nice" << endl;
	else
		cout << "Sad" << endl;

	delete[] arr;

	return 0;
}