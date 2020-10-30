# Simultaneous Equations Solver

連立一次方程式の計算をC++で実装してみた

### 前進代入法

`ex01/main.cpp`では前進代入法によって解を求める．

入力引数は下三角行列であるとした．

出力例は以下の通り．

```
This program solves linear system of equations A x = b, where A is a lower triangular matrix.
Coefficient matrix A:
8 0 0 0
2 3 0 0
6 5 4 0
7 8 9 8
Right hand side of equations b:
8
8
12
-2
Solution x:
1
2
-1
-2
```

### 後進代入法

`ex02/main.cpp`では後進代入法によって解を求める．

入力引数は上三角行列であるとした．

出力例は以下の通り．

```
This program solves linear system of equations A x = b, 
where A is a upper triangular matrix.
Coefficient matrix A:
1 2 4 3
0 3 2 1
0 0 4 3
0 0 0 1
Right hand side of equations b:
1
2
2
-2
Solution x:
-1
0
2
-2
```

### ガウス消去法

`ex03/main.cpp`ではガウス消去法によって解を求める．

出力例は以下の通り．

```
This program solves linear system of equations A x = b.
Coefficient matrix A:
1  2 -1
1 -1  6
3  1  1
Right hand side of equations b:
3
7
8
Solution x:
2
1
1

```

### LU分解を用いる方法

`ex04/main.cpp`ではLU分解によって解を求める．

出力例は以下の通り．

```
This program solves linear system of equations using LU decomp.
Coefficients:
1 2 3 4
2 5 4 3
3 4 6 5
6 5 4 7
Right hand side of equations:
30
36
49
56
L:
1  0  0  0
2  1  0  0
3 -2  1  0
6 -7  4  1
U:
1   2   3   4
0   1  -2  -5
0   0  -7 -17
0   0   0  16
Solution x:
1
2
3
4
```

### ガウスザイデル法

`ex05_1/main.cpp`ではガウスザイデル法によって解を求める．

出力例は以下の通り．

```
This program solves linear system of equations by Gauss-Seidel method
Coefficients:
4  2 -1
1 -5  6
3  1  6
Right hand side of equations:
3
7
8
Gauss-Seidel iteration successfully converges.
Solution:
1.05144
-0.183861
0.838256
```

