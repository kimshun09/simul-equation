#include <iostream>
#include "Eigen/Core"

using namespace std;
using namespace Eigen;

VectorXd forwardSubstitute(const MatrixXd &A, const VectorXd &b) {
    VectorXd x(b.size());

    // --------------------------------------------------
    //  コードを作成して挿入
    // --------------------------------------------------

    // x1 = b1 / a11
    x(0) = b(0) / A(0, 0);

    // xi = (bi - sum{ai}) / aii によってi=1からベクトルbの要素数まで繰り返し求める
    for(int i=1; i<b.size(); i++) {
        // sum{ax}の計算
        double ax = 0;
        for(int j=0; j<i; j++) {
            ax += A(i, j) * x(j);
        }
        x(i) = (b(i) - ax) / A(i, i);
    }


    return x;
}

int main() {

    int n = 4;
    MatrixXd A(n,n);
    VectorXd b(n);

    A <<
        8, 0, 0, 0,
        2, 3, 0, 0,
        6, 5, 4, 0,
        7, 8, 9, 8;

    b << 8, 8, 12, -2;

    cout << "This program solves linear system of equations A x = b, where A is a lower triangular matrix." << endl;
    cout << "Coefficient matrix A:" << endl;
    cout << A << endl;
    cout << "Right hand side of equations b:" << endl;
    cout << b << endl;

    cout << "Solution x:" << endl;
    cout << forwardSubstitute(A, b) << endl;


    //　自分で定義した連立方程式
    A <<
      5, 0, 0, 0,
      2, 8, 0, 0,
      6, 2, 9, 0,
      8, 8, 2, 1;

    b << 10, 14, -5, -6;

    cout << "Coefficient matrix A:" << endl;
    cout << A << endl;
    cout << "Right hand side of equations b:" << endl;
    cout << b << endl;

    cout << "Solution x:" << endl;
    cout << forwardSubstitute(A, b) << endl;



    return 0;
}
