#include <iostream>

using namespace std;

int n, m;
int** map, ** dp;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int recur(int r, int c);   

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	map = new int* [n + 2];
	for (int i = 0; i < n + 2; i++) {
		*(map + i) = new int[m + 2]();
	}

	dp = new int* [n + 2];
	for (int i = 1; i <= n; i++) {
		*(dp + i) = new int[m + 2]; 
		for (int j = 1; j <= m; j++) {
			*(*(dp + i) + j) = -1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> *(*(map + i) + j);
		}
	}

	*(*(dp + 1) + 1) = 1;
	
	cout << recur(n, m) << '\n';

	for (int i = 0; i < n + 2; i++) {
		delete[] *(map + i);
	}
	delete[] map;

	for (int i = 1; i <= n; i++) {
		delete[] *(dp + i);
	}
	delete[] dp;

	return 0;
}


int recur(int r, int c) {
	if (*(*(dp + r) + c) != -1) {
		return *(*(dp + r) + c);
	}

	int nowValue = *(*(map + r) + c);
	int count = 0;

	for (int i = 0; i < 4; i++) {
		if(*(*(map + r + dr[i]) + c + dc[i]) > nowValue){
			count += recur(r + dr[i], c + dc[i]);
		}
	}

	*(*(dp + r) + c) = count;

	return count;
}