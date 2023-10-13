//
// Created by marktiwnzhao on 2022/10/18.
//
#include <iostream>
using namespace std;
void swap(char *p1, char *p2) {
    char tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
void swap1(char& p1, char& p2) {
    char tmp = p1;
    p1 = p2;
    p2 = tmp;
}
void swap(char **p1, char **p2) {
    char *tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
int main() {
    char a = 'a';
    char b = 'b';
//    swap(&a, &b);
//    cout << a << " " << b << endl;
    swap1(a, b);
    cout << a << " " << b << endl;
    char *p1 =(char*) "abcd";
    char *p2 =(char*) "1234";
    //swap(&p1, &p2);//交换两个字符串
    //swap1(p1, p2);
    cout << p1 << endl << p2 << endl;
    return 0;
}
