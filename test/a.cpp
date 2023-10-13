//
// Created by marktiwnzhao on 2022/9/30.
//
#include <iostream>
class Error {};
class fileError:public Error {};
class eError:public Error {};
int main() {
    try {
        fileError f;
        Error* e = &f;
        throw e;
    } catch(fileError& a) {
        std::cout << "a" << std::endl;
    }

}
