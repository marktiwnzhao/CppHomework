//
// Created by marktiwnzhao on 2022/11/10.
//
#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    string x;
    cin >> x;
    printf("%d\n", x.substr(2).size());
    printf("%s", x.substr(2).c_str());
    return 0;
}
