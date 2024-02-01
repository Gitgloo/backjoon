#include <iostream>
#include <stack>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

using namespace std;

struct node {
	int index, value;
};

stack<node> s;
long long int maxArea = 0;

void func(int index, int value);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	s.push({ 0, 0 });

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp;

		cin >> temp;
		func(i, temp);
	}

	func(n + 1, 0);

	cout << maxArea << '\n';

	return 0;
}

void func(int index, int value) {
	if (value < s.top().value) {
		int lastIndex = 0;
		while (value < s.top().value) {
			node temp = s.top();
			maxArea = MAX(maxArea, (long long int)temp.value * (index - temp.index));
			lastIndex = temp.index;
			s.pop();
		}
		index = lastIndex;
	}
	s.push({ index, value });
}