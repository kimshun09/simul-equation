#include <iostream>
#include "Eigen/Core"

using namespace std;
using namespace Eigen;

VectorXd backwardSubstitute(const MatrixXd& A, const VectorXd& b) {
    VectorXd x(b.size());


    // --------------------------------------------------
    //  コードを作成して挿入
    // --------------------------------------------------

    int n = b.size();

    // xn = bn / ann
    x(n-1) = b(n-1) / A(n-1, n-1);

    // xi = (bi - sum{ai}) / aii によってi=n-2からi=0まで繰り返し求める
    for(int i=n-2; i>=0; i--) {
        // sum{ax}の計算
        double ax = 0;
        for(int j=i+1; j<n; j++) {
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
        1, 2, 4, 3,
        0, 3, 2, 1,
        0, 0, 4, 3,
        0, 0, 0, 1;
    b << 1, 2, 2, -2;

    cout << "This program solves linear system of equations A x = b, where A is a upper triangular matrix." << endl;
    cout << "Coefficient matrix A:" << endl;
    cout << A << endl;
    cout << "Right hand side of equations b:" << endl;
    cout << b << endl;

    cout << "Solution x:" << endl;
    cout << backwardSubstitute(A, b) << endl;

    // 自分で定義した連立方程式
    A <<
            4, 7, 4, 2,
            0, 2, 2, 5,
            0, 0, 6, 1,
            0, 0, 0, 1;
    b << 9, 5, -3, -4;

    cout << "Coefficient matrix A:" << endl;
    cout << A << endl;
    cout << "Right hand side of equations b:" << endl;
    cout << b << endl;

    cout << "Solution x:" << endl;
    cout << backwardSubstitute(A, b) << endl;
    return 0;
}
