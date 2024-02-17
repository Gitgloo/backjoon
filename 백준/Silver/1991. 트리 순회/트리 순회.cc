#include <iostream>

using namespace std;

struct node {
	char left, right;
};

node nodes[26];

void printFront(char now);
void printMid(char now);
void printBack(char now);

int main(void) {
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		char now, left, right;

		cin >> now >> left >> right;
		nodes[now - 'A'].left = left;
		nodes[now - 'A'].right = right;
	}

	printFront('A');
	cout << '\n';
	printMid('A');
	cout << '\n';
	printBack('A');
	cout << '\n';

	return 0;
}

void printFront(char now) {
	if (now == '.')
		return;
	cout << now;
	printFront(nodes[now - 'A'].left);
	printFront(nodes[now - 'A'].right);
}

void printMid(char now) {
	if (now == '.')
		return;
	printMid(nodes[now - 'A'].left);
	cout << now;
	printMid(nodes[now - 'A'].right);
}

void printBack(char now) {
	if (now == '.')
		return;
	printBack(nodes[now - 'A'].left);
	printBack(nodes[now - 'A'].right);
	cout << now;
}