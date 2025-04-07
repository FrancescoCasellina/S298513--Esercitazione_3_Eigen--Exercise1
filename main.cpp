#include "Eigen/Eigen"
#include <iostream>

using namespace std;
using namespace Eigen;

MatrixXd Shape(const unsigned int &n) {
	VectorXd V = VectorXd::LinSpaced(n * n, 1, n * n);
	MatrixXd A = V.reshaped <RowMajor>(n, n);
	return A;
}

MatrixXd Rand(const unsigned int &n) {
	MatrixXd A = MatrixXd::Random(n, n) + MatrixXd::Constant(n, n, 1);
	return A;
}

MatrixXd Hilb(const unsigned int &n) {
	MatrixXd A(n,n);
	for(unsigned int i = 0; i < n; i++) {
		for(unsigned int j = 0; j < n; j++) {
			A(i, j) = 1.0 / (i + j + 1);
		}
	}
	return A;
}

string Check(const MatrixXd &A) {
	double DetA = A.determinant();
	string a;
	if (fabs(DetA) < 1e-10)
		a = "";
	else
		a = " not";
	return a;
}

int main () {
	int n = 4;
	srand(time(0));

	cout << "Note: n has been set to " << n << "\n" << endl;

	cout << "The matrix Shape(n): \n" << Shape(n) << "\nis"  << Check(Shape(n)) << " singular\n" << endl;
        cout << "The matrix Rand(n): \n"  << Rand(n)  << "\nis"  << Check(Rand(n))  << " singular\n" << endl;
        cout << "The matrix Hilb(n): \n"  << Hilb(n)  << "\nis"  << Check(Hilb(n))  << " singular\n" << endl;

	return 0;
}
