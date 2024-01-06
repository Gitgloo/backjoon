#include <iostream>;

using namespace std;

int main(void) {
	int n;
	bool arr[101][101] = { false };

	cin >> n;
	while (n--) {
		int x, y;

		cin >> x >> y;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				arr[x + i][y + j] = true;
			}
		}
	}

	int area = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (arr[i][j])
				area++;
		}
	}

	cout << area << endl;

	return 0;
}