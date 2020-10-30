#include <iostream>
#include "Eigen/Core"
#include "Eigen/LU"

using namespace std;
using namespace Eigen;

VectorXd backwardSubstitute(const MatrixXd& A, const VectorXd& b) {
    VectorXd x(b.size());


    // --------------------------------------------------
    //  コードを作成して挿入
    // --------------------------------------------------
    //　課題2と同じ
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

bool GaussianElimination(const MatrixXd& A0, const VectorXd& b0, VectorXd& x) {
    VectorXd b = b0; // 入力された行列が変更されるのを防ぐために，
    MatrixXd A = A0; // コピーした値を使って操作する（C++は値渡しであることに注意）
    int n = b.size();
    x.resize(n);

    // Aの1列目からn列目まで繰り返す
    for(int i = 0; i < n; ++i) {
        // ピボット探索（絶対値の一番大きいものを見つける)
        double pivotValue = abs(A(i,i));
        int pivotIndex = i;
        for(int j = i+1; j < n; ++j) {
            if(abs(A(j,i)) > pivotValue) {

                // 現在のピボット候補より大きい値を発見したため，
                // ピボット値とピボットインデックスを更新する
                // --------------------------------------------------
                //  コードを作成して挿入
                // --------------------------------------------------
                pivotIndex = j;
                pivotValue = abs(A(j, i));

            }
        }

        // ピボットの絶対値がある値より小さければ終了する
        // --------------------------------------------------
        //  コードを作成して挿入
        // --------------------------------------------------
        if(pivotValue<0.0000000001) {
            cout << "求解不能" << endl;
            return false;
        }


        if(pivotIndex != i) {

            // ピボットインデックスがiでなければ，
            // Aのi行とpivotIndex行，bのi番目の要素とpivotIndex番目の要素を入れ替える
            // --------------------------------------------------
            //  コードを作成して挿入
            // --------------------------------------------------
            // A.row(i)によってAのi行目をベクトルとして得られる
            VectorXd t = A.row(i);
            A.row(i) = A.row(pivotIndex);
            A.row(pivotIndex) = t;

            double u = b(i);
            b(i) = b(pivotIndex);
            b(pivotIndex) = u;

        }

        for(int j = i+1; j < n; ++j) {

            // 変数の消去操作
            // Aのi行目をr倍してj行目から引く
            // 同様にbのi番目の要素をr倍してj番目の要素から引く
            // --------------------------------------------------
            //  コードを作成して挿入
            // --------------------------------------------------
            // r = aji / aii
            double r = A(j, i) / A(i, i);
            // Aのj行目 -= Aのi行目 * r
            A.row(j) -= A.row(i) * r;
            // bj -= bi * r;
            b(j) -= b(i) * r;

        }

    }


    // 後退代入
    // --------------------------------------------------
    //  コードを作成して挿入
    // --------------------------------------------------
    x = backwardSubstitute(A, b);

    return true;
}

int main() {

    int n = 3;
    MatrixXd A(n,n);
    VectorXd b(n);
    VectorXd x(n);

    A <<
      1, 2, -1,
            1, -1, 6,
            3, 1,  1;

    b << 3, 7, 8;

    cout << "This program solves linear system of equations A x = b." << endl;
    cout << "Coefficient matrix A:" << endl;
    cout << A << endl;
    cout << "Right hand side of equations b:" << endl;
    cout << b << endl;
    if (GaussianElimination(A, b, x)) {
        cout << "Solution x:" << endl;
        cout << x << endl;
    } else {
        cout << "error: too small pivot" << endl;
    }

    return 0;
}
