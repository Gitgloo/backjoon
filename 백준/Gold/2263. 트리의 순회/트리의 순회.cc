#include <iostream>
#include <vector>

using namespace std;

vector<int> inorder;
vector<int> postorder;
vector<int> inorderMap;
vector<bool> visited;

void printPreorder(int right1, int right2);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;
	inorder.resize(n);
	postorder.resize(n);
	inorderMap.resize(n + 1);
	visited.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
		inorderMap[inorder[i]] = i;
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

	int parent = postorder[right2];
	int diff = right1 - inorderMap[parent] + 1;

	visited[right2] = true;
	cout << parent << ' ';
	printPreorder(right1 - diff, right2 - diff);
	printPreorder(right1, right2 - 1);
}