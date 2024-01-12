#include <iostream>

using namespace std;

typedef struct s_node{
	s_node* front = NULL;
	s_node* rear = NULL;
	int data = 0;
	int index = 0;
}node;

typedef struct s_list {
	s_node* head = NULL;
	s_node* tail = NULL;
	int size = 0;

	void push(int x, int index) {
		node* newNode = new node;
		newNode->data = x;
		newNode->index = index;

		if (size == 0) {
			head = newNode;
		} else {
			tail->rear = newNode;
			head->front = newNode;
			newNode->front = tail;
		}
		tail = newNode;

		size++;
	}
}mylist;

int main(void) {
	int n;
	mylist list;

	cin >> n;
	for(int i = 1; i <= n; i++) {
		int temp;

		cin >> temp;
		list.push(temp, i);
	}

	node* now = list.head;

	int index = 1;
	while (true) {
		int next = now->data;

		cout << now->index << ' ';

		if (--list.size == 0)
			break;

		node* temp = now;
		if (next > 0) {
			now = now->rear;
			temp->front->rear = temp->rear;
			temp->rear->front = temp->front;
			for (int i = 0; i < next - 1; i++) {
				now = now->rear;
			}
		}
		else {
			now = now->front;
			temp->front->rear = temp->rear;
			temp->rear->front = temp->front;
			for (int i = 0; i < -next - 1; i++) {
				now = now->front;
			}
		}
		delete temp;
	}

	cout << endl;

	return 0;
}