//
// Created by marktiwnzhao on 2022/10/18.
//

#include <iostream>
#pragma pack(push)
#pragma pack(2)
#pragma pack(pop)
union B{
    char b;
    int a;
    short c;
};

int main() {
    std::cout << sizeof(B) << std::endl;
    B b;
    b.a = '0';
    b.b = 1;
    b.c = 2;
    std::cout << b.a << b.c;
    std::cout << b.b;
    return 0;
}
