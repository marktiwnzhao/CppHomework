//
// Created by marktiwnzhao on 2022/11/18.
//
#include<iostream>
using namespace std;
class A{
    int x;
public:
    void showInfo() {cout << "father" << endl;}
    void showInfo(int x) {cout << "fa" << ":" << x << endl;}
};
class B: public A {
    int y;
public:
    using A::showInfo;
    void showInfo() {cout << "son" << endl;}
};
int main() {
    B b;
    A* a = &b;
    a->showInfo();
    b.showInfo(3);
    return 0;
}


