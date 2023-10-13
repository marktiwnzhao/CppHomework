//
// Created by marktiwnzhao on 2022/10/6.
//
#include<iostream>
#include <vector>

using namespace std;
int main() {
    int len;
    cin >> len;
    vector<long> num(len);
    for(int i = 0; i < len; ++i) {
        cin >> num[i];
    }
    int lcd = 1;
    int lcd1 = 1;
    for(int i = 0; i < len - 1; ++i) {
        if(num[i] > num[i+1])
            lcd1++;
        else {
            if(lcd1 > lcd)
                lcd = lcd1;
            lcd1 = 1;
        }
    }
    lcd = lcd1 > lcd ? lcd1 : lcd;
    cout << lcd << endl;
    return 0;
}
