#include <iostream>

using namespace std;

int main(void) {
	int score;
	char grade = 'F';

	cin >> score;

	if (score >= 90)
		grade = 'A';
	else if (score >= 80)
		grade = 'B';
	else if (score >= 70)
		grade = 'C';
	else if (score >= 60)
		grade = 'D';

	cout << grade << endl;

	return 0;
}