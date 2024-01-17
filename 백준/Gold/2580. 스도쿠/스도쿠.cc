#include <iostream>
#include <vector>

using namespace std;

typedef struct s_blank {
	int r;
	int c;
}blank;

bool recur(int arr[][9], vector<blank>& blanks, int index);
bool isPossible(int arr[][9], int n, int r, int c);

int main(void) {
	int arr[9][9];
	vector<blank> blanks;


	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				blanks.push_back({ i,j });
		}
	}

	recur(arr, blanks, 0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}

bool recur(int arr[][9], vector<blank>& blanks, int index) {
	if (blanks.size() == index)
		return true;

	int r = blanks[index].r, c = blanks[index].c;
	for (int i = 1; i <= 9; i++) {
		if (isPossible(arr, i, r, c)) {
			arr[r][c] = i;
			if (recur(arr, blanks, index + 1))
				return true;
			arr[r][c] = 0;
		}
	}

	return false;
}

bool isPossible(int arr[][9], int n, int r, int c) {
	for (int i = 0; i < 9; i++) {
		if (arr[i][c] == n || arr[r][i] == n)
			return false;
	}

	int startR = r / 3 * 3, startC = c / 3 * 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[startR + i][startC + j] == n)
				return false;
		}
	}

	return true;
}