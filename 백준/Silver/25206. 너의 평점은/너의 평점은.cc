#include <iostream>

using namespace std;

int main(void) {
	double sumPoint = 0;
	double sumScore = 0;

	for (int i = 0; i < 20; i++) {
		double point;
		string subject, grade;

		cin >> subject >> point >> grade;

		if (grade.compare("A+") == 0) {
			sumScore += point * 4.5;
		}
		else if (grade.compare("A0") == 0) {
			sumScore += point * 4.0;
		}
		else if (grade.compare("B+") == 0) {
			sumScore += point * 3.5;
		}
		else if (grade.compare("B0") == 0) {
			sumScore += point * 3.0;
		}
		else if (grade.compare("C+") == 0) {
			sumScore += point * 2.5;
		}
		else if (grade.compare("C0") == 0) {
			sumScore += point * 2.0;
		}
		else if (grade.compare("D+") == 0) {
			sumScore += point * 1.5;
		}
		else if (grade.compare("D0") == 0) {
			sumScore += point * 1.0;
		}

		if(grade.compare("P") != 0)
			sumPoint += point;
	}

	cout << sumScore / sumPoint << endl;

	return 0;
}