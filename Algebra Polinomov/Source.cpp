#include "Monom.h"
#include <iostream>
using namespace std;
int main() {
	Monom A(-3, 70465);
	cout << A.ToString(5, 10) << endl;
	Monom B(10, 5678);
	cout << B.ToString(5, 10) << endl;
	Monom C(A);
	cout << C.ToString(5, 10) << endl;
	B = A;
	cout << B.ToString(5, 10) << endl;
	C = A + B;
	cout << C.ToString(5, 10) << endl;
	C = A - B;
	cout << C.ToString(5, 10) << endl;
	C = A * 3;
	cout << C.ToString(5, 10) << endl;
	C = A * 0;
	cout << C.ToString(5, 10) << endl;
	Monom D(2, 1204);
	B = A.multiply(D, 10, 5);
	cout << B.ToString(5, 10) << endl;
	string str = A.ToString(5, 10);
	Monom T(str, 5, 10);
	cout << T.ToString(5, 10) << endl;
	Monom F("x1x4^2x0", 5, 10);
	cout << F.ToString(5, 10) << endl;
}