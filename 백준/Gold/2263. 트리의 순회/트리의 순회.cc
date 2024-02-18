#include <iostream>
#include <vector>

using namespace std;

vector<int> inorder;
vector<int> postorder;
vector<bool> visited;

void printPreorder(int right1, int right2);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;
	inorder.resize(n);
	postorder.resize(n);
	visited.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> postorder[i];
	}

	printPreorder(n - 1, n - 1);

	return 0;
}

void printPreorder(int right1, int right2) {
	if (right2 < 0 || visited[right2])
		return;
	visited[right2] = true;

	int i = -1;
	int parent = postorder[right2];

	cout << parent << ' ';

	while (inorder[right1 - ++i] != parent);
	
	printPreorder(right1 - i - 1, right2 - i - 1);
	printPreorder(right1, right2 - 1);
}