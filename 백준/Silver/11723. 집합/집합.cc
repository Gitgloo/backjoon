#include <iostream>

#define MAX_X 20
#define MASK ((1 << 21) - 1)

using namespace std;

int S;

void add(int x);
void remove(int x);
bool check(int x);
void toggle(int x);
void all();
void empty();

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m;

	cin >> m;
	while (m--) {
		string command;

		cin >> command;
		if (command == "all") {
			all();
		} else if (command == "empty") {
			empty();
		} else {
			int x;

			cin >> x;
			if (command == "add") {
				add(x);
			} else if(command == "remove") {
				remove(x);
			} else if (command == "check") {
				cout << check(x) << '\n';
			} else {
				toggle(x);
			}
		}
	}

	return 0;
}

void add(int x) {
	S |= (1 << x);
}

void remove(int x) {
	S &= ((1 << x) ^ MASK);
}

bool check(int x) {
	return S & (1 << x);
}

void toggle(int x) {
	S ^= (1 << x);
}

void all() {
	S |= MASK;
}

void empty() {
	S &= 0;
}