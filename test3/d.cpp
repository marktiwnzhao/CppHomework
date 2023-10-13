//
// Created by marktiwnzhao on 2022/11/24.
//
#include<iostream>
using namespace std;


class Array1D{//Surrogate 多维，proxy class
public:
    explicit Array1D(int *p) { this->p = p; }
    int& operator[ ] (int index) { return p[index]; }
    const int operator[ ] (int index) const { return p[index]; }
private:
    int *p;
};
class Array2D{
private:
    int *p;
    int num1, num2;
public:
    Array2D(int n1, int n2) {
        p = new int[n1 * n2];
        num1 = n1;
        num2 = n2;
    }
    virtual ~Array2D() {
        delete [] p;
    }
    Array1D operator[](int index) {
        return Array1D(p + index * num2);//return的值和int*相同，构造函数不能声明成显式构造函数。
    }
    //这里为什么是array1D?通过构造函数进行类型转换
    const Array1D operator[] (int index) const {
        return Array1D(p+index*num2);
    }
};



int main() {
    Array2D array2D(2, 3);
    array2D[1][2] = 1;
    cout << array2D[1][2];
    return 0;
}