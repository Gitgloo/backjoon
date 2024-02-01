#include <iostream>
#include <stack>

using namespace std;

struct node{
	int index, value;
};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	stack<node> s;

	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		*(arr + i) = -1;
	}

	for(int i = 0; i < n; i++) {
		int temp;

		cin >> temp;
		if (s.size() && s.top().value < temp) {
			while (s.size() && s.top().value < temp) {
				*(arr + s.top().index) = temp;
				s.pop();
			}
		}
		s.push({ i,temp });
	}

	for (int i = 0; i < n; i++) {
		cout << *(arr + i) << ' ';
	}
	cout << '\n';

	delete[] arr;
	

	return 0;
}