#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n, m, min{ 64 };

	cin >> n >> m;

	vector<vector<int>> board(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char ch;
			
			cin >> ch;
			if (ch == 'B')
				board[i][j] = 1;
		}
	}

	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			int count = 0;
			for (int r = 0; r < 8; r++) {
				for (int c = 0; c < 8; c++) {
					if ((r + c) % 2 == board[i + r][j + c]) {
						count++;
					}
				}
			}

			if (count < min) {
				min = count;
			}
			if (64 - count < min) {
				min = 64 - count;
			}
		}
	}

	cout << min << endl;

	return 0;
}