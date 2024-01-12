#include <iostream>

using namespace std;

typedef struct s_queue {
	int capacity = 3;
	int left = 0;
	int right = 0;
	int* arr = new int[capacity];

	void push(int x) {
		if ((left - right + capacity) % capacity == 1) {
			int* temp = new int[2 * capacity];

			int index = 1;
			while (size()) {
				temp[index++] = pop();
			}

			left = 0;
			right = index - 1;
			capacity = 2 * capacity;
			delete[] arr;
			arr = temp;
		}

		right = (right + 1) % capacity;
		arr[right] = x;
	}

	int pop() {
		if (size() == 0)
			return -1;

		left = (left + 1) % capacity;
		return arr[left];
	}

	int size() {
		return (right - left + capacity) % capacity;
	}

	int empty() {
		return size() == 0;
	}

	int front() {
		if (size() == 0)
			return -1;

		return arr[(left + 1) % capacity];
	}

	int back() {
		if (size() == 0)
			return -1;

		return arr[right];
	}
} myqueue;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	string answer = "";
	myqueue q;

	cin >> N;
	while (N--) {
		string command;

		cin >> command;
		if (command.compare("push") == 0) {
			int X;

			cin >> X;
			q.push(X);
		} else if (command.compare("pop") == 0) {
			cout << q.pop() << '\n';
		} else if (command.compare("size") == 0) {
			cout << q.size() << '\n';
		} else if (command.compare("empty") == 0) {
			cout << q.empty() << '\n';
		} else if (command.compare("front") == 0) {
			cout << q.front() << '\n';
		} else if (command.compare("back") == 0) {
			cout << q.back() << '\n';
		}
	}

	cout << answer;

	return 0;
}