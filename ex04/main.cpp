#include <iostream>
#include "Eigen/Core"

using namespace std;
using namespace Eigen;

VectorXd forwardSubstitute(const MatrixXd& A, const VectorXd& b) {
    VectorXd x(b.size());

    //
    // Write your own code here
    //
    // 課題1と同じ
    x(0) = b(0) / A(0, 0);
    for(int i=1; i<b.size(); i++) {
        double ax = 0;
        for(int j=0; j<i; j++) {
            ax += A(i, j) * x(j);
        }
        x(i) = (b(i) - ax) / A(i, i);
    }

    return x;
}

VectorXd backwardSubstitute(const MatrixXd& A, const VectorXd& b) {
    VectorXd x(b.size());

    //
    // Write your own code here
    //
    // 課題2と同じ
    int n = b.size();
    x(n-1) = b(n-1) / A(n-1, n-1);
    for(int i=n-2; i>=0; i--) {
        double ax = 0;
        for(int j=i+1; j<n; j++) {
            ax += A(i, j) * x(j);
        }
        x(i) = (b(i) - ax) / A(i, i);
    }

    return x;
}


bool LUDecomp(const MatrixXd& A, MatrixXd& L, MatrixXd& U) {

    int n = A.rows();

    U = A;
    // MatrixXd::Identity(n, n)で単位行列を得られる
    L = MatrixXd::Identity(n,n);

    //
    // Write your own code here
    //
    // i=0からn-1まで繰り返す
    for(int i=0; i<n; i++) {
        // さらにj=i+1からn-1まで繰り返す
        for(int j=i+1; j<n; j++) {
            double r = U(j, i) / U(i, i);
            // i列目からn列目まで　Ujk -= r*Ui を行う
            for(int k=i; k<n; k++)
                U(j, k) -= r * U(i, k);
            L(j, i) = r;

        }
    }

    return true;
}


int main() {

    int n = 4;
    MatrixXd A(n,n);
    VectorXd b(n);
    VectorXd x(n);

    A <<
      1, 2, 3, 4,
            2, 5, 4, 3,
            3, 4, 6, 5,
            6, 5, 4, 7;
    b << 30, 36, 49, 56;

    cout << "This program solves linear system of equations using LU decomp." << endl;
    cout << "Coefficients:" << endl;
    cout << A << endl;
    cout << "Right hand side of equations:" << endl;
    cout << b << endl;

    MatrixXd L;
    MatrixXd U;

    LUDecomp(A,L,U);

    cout << "L:" << endl;
    cout << L << endl;

    cout << "U:" << endl;
    cout << U << endl;

    VectorXd c = forwardSubstitute(L, b);
    x = backwardSubstitute(U, c);

    cout << "Solution x:" << endl;
    cout << x << endl;

    return 0;
}
