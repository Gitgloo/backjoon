#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> preOrder;
stack<int> postOrder;

void recur(int left, int right);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int temp;

		cin >> temp;
		if (cin.eof())
			break;
		preOrder.push_back(temp);
	}

	recur(0, preOrder.size() - 1);

	while (postOrder.size()) {
		cout << postOrder.top() << '\n';
		postOrder.pop();
	}


	return 0;
}

void recur(int left, int right) {
	if (left > right)
		return;

	int first = preOrder[left];
	int index = right;

	postOrder.push(first);
	while (index > left && preOrder[index] > first) {
		index--;
	}
	recur(index + 1, right);
	recur(left + 1, index);
}