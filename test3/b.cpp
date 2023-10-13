//
// Created by marktiwnzhao on 2022/11/15.
//
#include<iostream>
#include<cstring>
using namespace std;


class Student {
protected:int id;
public:
    char nickname[16];
    void set_ID (int x) {id = x;}
    void SetNickName (char *s) {strcpy(nickname,s);}
    void showInfo () {cout << "father" << endl;}
    void showInfo(int x) {cout << x << endl;}
};

class Undergraduated_Student : public Student{
    int dept_no;//学院编号
public:
    void setDeptNo(int x){dept_no = x;}
    void showInfo() {
        cout << "son" << endl;
    }
};

int main() {
    Undergraduated_Student us;
    us.showInfo();
    return 0;
}


