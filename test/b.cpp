//
// Created by marktiwnzhao on 2022/9/30.
//
int f(int, int = 1, int = 3);
int f(int a = 2, int b, int c) {
    return a + b + c;
}
