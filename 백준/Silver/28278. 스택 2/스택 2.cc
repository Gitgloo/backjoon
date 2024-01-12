#include <iostream>

using namespace std;

typedef struct s_stack {
	int capacity = 100;
	int index = -1;
	int* arr = new int[capacity];

	void push(int x) {
		if (index + 1 == capacity) {
			int* temp = new int[2 * capacity];

			for (int i = 0; i < capacity; i++) {
				temp[i] = arr[i];
			}

			delete[] arr;
			arr = temp;
			capacity *= 2;
		}

		arr[++index] = x;
	}

	int pop() {
		if (index == -1)
			return -1;

		return arr[index--];
	}

	int size() {
		return index + 1;
	}

	int empty() {
		return index == -1;
	}

	int top() {
		if (index == -1)
			return -1;

		return arr[index];
	}
}stack;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	stack s;

	cin >> n;
	while (n--) {
		int command;

		cin >> command;
		if (command == 1) {
			int temp;

			cin >> temp;
			s.push(temp);
		} else if (command == 2) {
			cout << s.pop() << '\n';
		} else if (command == 3) {
			cout << s.size() << '\n';
		} else if (command == 4) {
			cout << s.empty() << '\n';
		} else {
			cout << s.top() << '\n';
		}
	}

	return 0;
}