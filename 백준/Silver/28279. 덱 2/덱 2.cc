#include <iostream>

using namespace std;

typedef struct s_node {
	s_node* front = NULL;
	s_node* rear = NULL;
	int data = 0;
}node;

typedef struct s_deque {
	int count = 0;
	s_node* head = NULL;
	s_node* tail = NULL;

	void pushFront(int x) {
		node* newNode = new node;

		newNode->data = x;

		if (count == 0) {
			tail = newNode;
		} else {
			head->front = newNode;
			newNode->rear = head;
		}

		head = newNode;
		count++;
	}

	void pushBack(int x) {
		node* newNode = new node;

		newNode->data = x;

		if (count == 0) {
			head = newNode;
		}
		else {
			tail->rear = newNode;
			newNode->front = tail;
		}
		
		tail = newNode;
		count++;
	}

	int popFront() {
		if (count == 0) {
			return -1;
		}

		int ret = head->data;

		if (count == 1) {
			head = NULL;
			tail = NULL;
		} else {
			head->rear->front = NULL;
			head = head->rear;
		}

		count--;

		return ret;
	}

	int popBack() {
		if (count == 0) {
			return -1;
		}

		int ret = tail->data;

		if (count == 1) {
			head = NULL;
			tail = NULL;
		}
		else {
			tail->front->rear = NULL;
			tail = tail->front;
		}

		count--;

		return ret;
	}

	int size() {
		return count;
	}

	int empty() {
		return count == 0;
	}

	int front() {
		if (count == 0) {
			return -1;
		}

		return head->data;
	}

	int back() {
		if (count == 0) {
			return -1;
		}

		return tail->data;
	}
}mydeque;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	mydeque dq;
	
	cin >> n;
	while (n--) {
		int command;

		cin >> command;
		if (command == 1) {
			int x;

			cin >> x;
			dq.pushFront(x);
		} else if (command == 2) {
			int x;

			cin >> x;
			dq.pushBack(x);
		} else if (command == 3) {
			cout << dq.popFront() << '\n';
		} else if (command == 4) {
			cout << dq.popBack() << '\n';
		} else if (command == 5) {
			cout << dq.size() << '\n';
		} else if (command == 6) {
			cout << dq.empty() << '\n';
		} else if (command == 7) {
			cout << dq.front() << '\n';
		} else if (command == 8) {
			cout << dq.back() << '\n';
		}
	}

	return 0;
}