//
// Created by marktiwnzhao on 2022/10/4.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int num1[1000];
    int num2[1000];
    int num[1000];
    for(int i = 0; i < 1000; ++i) {
        num1[i] = num2[i] = 0;
    }
    num1[999] = 1;
    num2[999] = 2;
    if(n == 2) {
        cout << 2;
        return 0;
    }
    if(n == 1) {
        cout << 1;
        return 0;
    }
    if(n >= 3) {
        for(int i = 3; i <= n; i++) {
            for(int j = 0; j < 1000; ++j) {
                num[j] = 0;
            }
            for(int j = 999; j > 0; --j) {
                if(num[j] + num1[j] + num2[j] >= 10) {
                    num[j] = (num[j] + num1[j] + num2[j] - 10);
                    num[j - 1]++;
                } else num[j] = num[j] + num1[j] + num2[j];
            }
            copy(begin(num2), end(num2), begin(num1));
            copy(begin(num), end(num), begin(num2));
        }
    }
    bool isTrue = false;
    for(int i = 0; i < 1000; ++i) {
        if(num2[i] > 0) isTrue = true;
        if(isTrue) cout << num2[i];

    }

    return 0;
}