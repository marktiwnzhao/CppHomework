//
// Created by marktiwnzhao on 2022/10/4.
//
#include<iostream>
#include <vector>

using namespace std;
int getTime(string s) {
    int a = s.at(0) - '0';
    a = a*10 + s.at(1) - '0';
    int b = s.at(3) - '0';
    b = b*10 + s.at(4) - '0';
    return a*60 + b;
}
int main() {
    int n;
    cin >> n;
    cin >> ws;
    string s;
    vector<vector<int>> Interval(n, vector<int>(2));
    getline(cin, s);
    Interval[0][0] = getTime(s.substr(0, 5));
    Interval[0][1] = getTime(s.substr(6, 5));
    for(int i = 1; i < n; ++i) {
        getline(cin, s);
        int j;
        for(j = i - 1; j >= 0 && getTime(s.substr(6, 5)) < Interval[i][1]; --j) {
            Interval[j+1][0] = Interval[j][0];
            Interval[j+1][1] = Interval[j][1];
        }
        Interval[j+1][0] = getTime(s.substr(0, 5));
        Interval[j+1][1] = getTime(s.substr(6, 5));
    }
    int count = 1;
    int edge = Interval[0][1];
    for(int i = 1; i < n; ++i) {
        if(edge <= Interval[i][0]) {
            count++;
            edge = Interval[i][1];
        }
    }
    cout << n - count << endl;
    return 0;
}
