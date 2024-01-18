#include <iostream>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

using namespace std;

int main(void) {
	int n, max{ -1000 }, sum{ 0 };

	cin >> n;
	while (n--) {
		int temp;

		cin >> temp;
		max = MAX(max, temp);

		if (temp < 0 && sum > 0)
			max = MAX(max, sum);
		if (sum + temp > 0)
			sum += temp;
		else
			sum = 0;
	}

	if(sum > 0)
		max = MAX(max, sum);

	cout << max << endl;

	return 0;
}