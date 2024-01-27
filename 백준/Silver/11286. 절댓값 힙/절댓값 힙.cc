#include <iostream>
#define ABS(x) ((x) < 0 ? -(x) : (x))

using namespace std;

void swap(int* a, int* b);

class PriorityQueue {
private:
	int* arr = nullptr;
	int size = 0;

public:
	PriorityQueue(int capacity) {
		arr = new int[capacity + 1];
	}

	~PriorityQueue() {
		delete[] arr;
	}

	void push(int x) {
		int now = ++size;

		*(arr + now) = x;
		while (now / 2 > 0 && compare(*(arr + now), *(arr + now / 2))) {
			swap(arr + now, arr + now / 2);
			now = now / 2;
		}
	}

	int pop() {
		if (!size) {
			return 0;
		}

		int now = 1;
		int ret = *(arr + now);

		*(arr + now) = *(arr + size--);
		while (true) {
			int next = 0;

			if (2 * now <= size && compare(*(arr + 2 * now), *(arr + now))) {
				next = 2 * now;
			}

			if (2 * now + 1 <= size && compare(*(arr + 2 * now + 1) , *(arr + now)) &&
				compare(*(arr + 2 * now + 1), *(arr + 2 * now))) {
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

	bool compare(int a, int b) {
		int absA = ABS(a);
		int absB = ABS(b);

		if (absA == absB) {
			return a < b;
		}

		return absA < absB;
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

