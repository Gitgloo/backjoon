#include <iostream>
#include <vector> // vector 사용
using namespace std;

int main(void) {
	int n, m;

	cin >> n >> m;
	
	vector<int> v(n + 1);

	while (m--) {
		int i, j, k;

		cin >> i >> j >> k;
		//for (int l = i; l <= j; l++) {
		//	v[l] = k;	// v.at(i)는 범위 검사하고 v[i]는 범위 검사 안함
		//}
		int* vecPtr1 = &v[i];
		for (size_t l = 0; l < j - i + 1; l++) {
			*(vecPtr1 + l) = k;
		}
	}

	int* vecPtr2 = &v[1];
	for (int i = 0; i + 1 < v.size(); i++) {
		cout << *(vecPtr2 + i) << ' ';
	}
	cout << endl;

	return 0;
}