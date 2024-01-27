#include <iostream>

#define MAX(x, y) ((x) < (y) ? (y) : (x))

using namespace std;

void swap(int* a, int* b);

class PriorityQueue {
private:
	int* arr = nullptr;
	int size = 0;

public:
	PriorityQueue(int capacity) {
		arr = new int[capacity + 1];
		*arr = -1;
	}

	~PriorityQueue() {
		delete[] arr;
	}

	void push(int x) {
		int now = ++size;

		*(arr + now) = x;
		while (*(arr + now) < *(arr + now / 2)) {
			swap(arr + now, arr + now / 2);
			now = now / 2;
		}
	}

	int pop() {
		if (!size) {
			return 0;
		}

		int ret = *(arr + 1);
		int now = 1;

		*(arr + now) = *(arr + size--);
		while (true) {
			int next = 0;

			if (2 * now <= size && *(arr + now) > *(arr + 2 * now)) {
				next = 2 * now;
			}

			if (2 * now + 1 <= size && *(arr + now) > *(arr + 2 * now + 1) &&
				*(arr + 2 * now) > *(arr + 2 * now + 1)) {
				next = 2 * now + 1;
			}

			if (next) {
				swap(arr + now, arr + next);
				now = next;
			}
			else {
				break;
			}
		}

		return ret;
	}
};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;
	PriorityQueue pq = PriorityQueue(n);
	while (n--) {
		int temp;

		cin >> temp;
		if (temp) {
			pq.push(temp);
		}
		else {
			cout << pq.pop() << '\n';
		}
	}

	return 0;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

