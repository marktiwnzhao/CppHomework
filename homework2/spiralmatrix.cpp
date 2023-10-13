//
// Created by marktiwnzhao on 2022/10/6.
//
#include<iostream>
#include <vector>

using namespace std;
void Print(vector<vector<int>> Matrix, int row, int col);
int main() {
    int row, col;
    cin >> row;
    cin >> col;
    vector<vector<int>> Matrix(row, vector<int>(col));
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            cin >> Matrix[i][j];
    Print(Matrix, row, col);
    return 0;
}
void Print(vector<vector<int>> Matrix, int row, int col) {
    if(row <= 0 || col <= 0) return;
    if(row == 1) {
        for (int i = 0; i < col; ++i)
            cout << Matrix[0][i] << " ";
        return;
    }
    if(col == 1) {
        for (int i = 0; i < row; ++i)
            cout << Matrix[i][0] << " ";
        return;
    }
    for(int i = 0; i < col; ++i)
        cout << Matrix[0][i] << " ";
    for(int i = 1; i < row-1; ++i)
        cout << Matrix[i][col-1] << " ";
    for(int i = col-1; i >= 0; --i)
        cout << Matrix[row-1][i] << " ";
    for(int i = row-2; i >= 1; --i)
        cout << Matrix[i][0] << " ";
    for(int i = 1; i < row-1; ++i) {
        Matrix[i].pop_back();
        Matrix[i].erase(Matrix[i].begin());
    }
    Matrix.erase(Matrix.begin());
    Matrix.pop_back();
    Print(Matrix, row-2, col-2);
}