//
// Created by marktiwnzhao on 2022/10/6.
//
#include<iostream>
#include <vector>

using namespace std;
void Print(vector<vector<int>> Matrix, int N) {
    for(int i = 0; i < N; ++i) {
        for (int j = 0; j < N-1; ++j)
            cout << Matrix[i][j] << " ";
        cout << Matrix[i][N-1] << endl;
    }
}
int main() {
    int N;
    int x;
    cin >> N;
    vector<vector<int>> Matrix(N, vector<int>(N));
    cin >> x;
    x /= 90;
    x %= 4;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> Matrix[i][j];
        }
    }
    vector<vector<int>> Matrix1(N, vector<int>(N));
    switch(x) {
        case 0:
            Print(Matrix, N);
            break;
        case 1:
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j)
                    Matrix1[j][i] = Matrix[N-1-i][j];
            Print(Matrix1, N);
            break;
        case 2:
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j)
                    Matrix1[i][j] = Matrix[N-1-i][N-1-j];
            Print(Matrix1, N);
            break;
        case 3:
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j)
                    Matrix1[j][i] = Matrix[i][N-1-j];

            Print(Matrix1, N);
            break;
    }

    return 0;
}
