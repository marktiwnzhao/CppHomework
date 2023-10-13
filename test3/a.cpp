#include <iostream>

//
// Created by marktiwnzhao on 2022/10/27.
//
using namespace std;

class B;
class A{
    int a;
public:
    friend class B;
    void show(B &b);
};
class B{
    int b;
public:
    friend class A;
    void show(A &a){
        std::cout << a.a;//这里是可以的
    }
};
void A::show (B &b){//只能在这里面实现
    std::cout << b.b;
}
