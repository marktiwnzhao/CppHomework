//
// Created by marktiwnzhao on 2022/10/18.
//
#include<iostream>
using namespace std;
enum OPRAND_TYPE {END=-1, ADD, SUB, MUL, GCD, LCM, QUO, RES};
typedef int (*FP)(int, int);
int add(int a, int b) {return a+b;}
int sub(int a, int b) {return a-b;}
int mul(int a, int b) {return a*b;}
int gcd(int a, int b) {
    while(b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}
int lcm(int a, int b) {return a*b / gcd(a, b);}
int quo(int a, int b) {return a / b;}
int res(int a, int b) {return a % b;}
int main() {
    FP op[7] = {add, sub, mul, gcd, lcm, quo, res};
    int n;
    cin >> n;
    int op1;
    int op2;
    string s;
    for(int i = 0; i < n; ++i) {
        cin >> op1;
        cin >> op2;
        cin >> s;
        if(s == "add") {
            cout << op[ADD](op1, op2);
            continue;
        }
        if(s == "sub") {
            cout << op[SUB](op1, op2);
            continue;
        }
        if(s == "mul") {
            cout << op[MUL](op1, op2);
            continue;
        }
        if(s == "lcm") {
            cout << op[LCM](op1, op2);
            continue;
        }
        if(s == "gcd") {
            cout << op[GCD](op1, op2);
            continue;
        }
        if(s == "quo") {
            cout << op[QUO](op1, op2);
            continue;
        }
        if(s == "res") {
            cout << op[RES](op1, op2);
        }
    }
    return 0;
}
