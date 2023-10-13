//
// Created by marktiwnzhao on 2022/10/6.
//
#include<iostream>
#include <map>
#include <vector>

using namespace std;
const int SIZE = 1000;
int main() {
    string cmd;
    getline(cin, cmd);
    //数据
    vector<char> data(SIZE);
    int p = 0;
    vector<int> bracket(SIZE);
    int top = 0;
    for(int i = 0; i < SIZE; ++i) {
        data[i] = 0;
    }
    //处理括号
    map<int, int> braMapLeft;
    map<int, int> braMapRight;
    for(int i = 0; i < cmd.length(); ++i) {
        if(cmd.at(i) == '[') {
            bracket[top] = i;
            top++;
            continue;
        }
        if(cmd.at(i) == ']') {
            braMapLeft[bracket[top-1]] = i;
            braMapRight[i] = bracket[top-1];
            top--;
            continue;
        }
    }
    //处理指令
    for(int i = 0; i < cmd.length(); ++i) {
        switch(cmd.at(i)) {
            case '>':p++;break;
            case '<':p--;break;
            case '+':data[p]++;break;
            case '-':data[p]--;break;
            case ',':
                cin.get(data[p]);
                break;
            case '.':
                cout << data[p];
                break;
            case '[':
                if(data[p] == 0)
                    i = braMapLeft[i];
                break;
            case ']':
                if(data[p] != 0)
                    i = braMapRight[i];
                break;
        }
    }

    return 0;
}
