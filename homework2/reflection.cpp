//
// Created by marktiwnzhao on 2022/10/6.
//
#include<iostream>
#include <vector>

using namespace std;
int main() {
    int x, y;
    cin >> x;
    cin >> y;
    vector<vector<int>> grid(10, vector<int>(10));
    vector<vector<int>> flag(10, vector<int>(10));
    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < 10; ++j) {
            cin >> grid[i][j];
            flag[i][j] = 1;
        }
    int weight = 0;
    double k = y*1.0 / x;
    if(k >= 2) {
        double x1 = 10 / k;
        int x11 = (int) x1;
        int a1;
        for(int i = 0; i <= x11; ++i) {
            a1 = (int)(i * k);
            double b = (i+1) * k;
            int b1 = (int) b;
            if(b - b1 == 0.0) --b1;
            for(; a1 <= b1 && a1 < 10; ++a1) {
                weight += grid[a1][i];
                flag[a1][i] = 0;
            }
        }
        int a2;
        for(int i = x11; i < 10; i++) {
            double a = 20 - i * k;
            a2 = (int) a;
            if(a - a2 == 0.0) --a2;
            if(a2 >= 10) a2 = 9;
            double b = 20 - (i+1) * k;
            int b1 = (int) b;
            for(; a2 >= b1 && a2 >= 0; --a2) {
                if(flag[a2][i]) {
                    weight += grid[a2][i];
                    flag[a2][i] = 0;
                }
            }
        }

    } else if(k < 2) {
        double x1 = 10 / k;
        int x11 = (int) x1;
        int a1;
        for(int i = 0; i <= x11; ++i) {
            a1 = (int) i * k;
            double b = (i+1) * k;
            int b1 = (int) b;
            if(b - b1 == 0.0) --b1;
            for(; a1 <= b1 && a1 < 10; ++a1) {
                weight += grid[a1][i];
                flag[a1][i] = 0;
            }
        }
        int a2;
        for(int i = x11; i < 10; i++) {
            double a = 20 - i * k;
            a2 = (int) a;
            if(a - a2 == 0.0) --a2;
            if(a2 >= 10) a2 = 9;
            double b = 20 - (i+1) * k;
            int b1 = (int) b;
            for(; a2 >= b1 && a2 >= 0; --a2) {
                if(flag[a2][i]) {
                    weight += grid[a2][i];
                    flag[a2][i] = 0;
                }
            }
        }
        int a3;
        for(int i = 9; i >= 0; --i) {
            double a = (int) (i - 19)* k + 20;
            int a3 = (int) a;
            if(a - a3 == 0.0) a3--;
            double b = (i - 20)*k + 20;
            int b1 = (int) b;
            for(;a3 >= b1 && a3 >= 0; --a3) {
                if(flag[a3][i]) {
                    weight += grid[a3][i];
                    flag[a3][i] = 0;
                }
            }

        }
    }
    cout << weight << endl;
    return 0;
}