#include <iostream>
#include "Eigen/Core"
#include "Eigen/LU"

using namespace std;
using namespace Eigen;

bool GaussSeidel(const MatrixXd& A, const VectorXd& b, VectorXd& x) {
    int n = x.size();
    int max_iter = 1000; // 繰り返しの上限
    double tol = 1e-4; // 停止許容誤差 (tolerance)

    x = VectorXd::Zero(n); // ゼロで初期化

    // 繰り返しの上限max_iter=1000まで繰り返す
    for(int iter = 0; iter < max_iter; ++iter) {

        // 以下の二つの変数は停止判定に用いる
        double deltaX = 0; // 更新によるxの変化の総和
        double sumAbsX = 0; // x^(k)の要素の絶対値の総和

        for(int i = 0; i < n; ++i) {
            double oldX = x(i); // 更新前の値を保持しておく

            // --------------------------------------------------
            //  x(i)を更新するコードを作成して挿入
            // --------------------------------------------------
            double sum1 = 0, sum2 = 0;
            for(int j=0; j<i; j++)
                sum1 += A(i, j) * x(j);
            for(int j=i+1; j<n; j++)
                sum1 += A(i, j) * x(j);
            x(i) = (b(i) - sum1 - sum2) / A(i, i);

            deltaX += abs(x(i) - oldX);
            sumAbsX += abs(oldX);
        }
        // xの相対変化量がtol=10^-4以下になったら終了
        if((deltaX / sumAbsX) < tol) {
            cout << "Gauss-Seidel iteration successfully converges." << endl;
            return true;
        }

    }

    cout << "Iteration reaches maximum." << endl;
    return false;
}

int main() {

    int n = 3;
    MatrixXd A(n,n);
    VectorXd b(n);
    VectorXd x(n);

    A << // 収束条件を満たす行列
      4, 2, -1,
            1, -5, 6,
            3, 1,  6;
    b << 3, 7, 8;

    cout << "This program solves linear system of equations by Gauss-Seidel method" << endl;

    cout << "Coefficients:" << endl;
    cout << A << endl;
    cout << "Right hand side of equations:" << endl;
    cout << b << endl;

    GaussSeidel(A, b, x);

    cout << "Solution:" << endl;
    cout << x << endl;

    return 0;
}
