//
// Created by marktiwnzhao on 2022/10/5.
//
#include<iostream>
#include <cstring>

using namespace std;

int main() {
    int *num = nullptr;
    int top = 0;
    bool isSet = false;
    int length = 0;
    int n;
    char s[20];
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> s;
        if(strcmp(s, "getSize") == 0) {
            cout << top << endl;
            continue;
        }
        if(strcmp(s, "getCapacity") == 0) {
            cout << length << endl;
            continue;
        }
        if(strcmp(s, "add") == 0) {
            int value;
            cin >> value;
            if(top == 0 && !isSet) {
                isSet = true;
                length = 10;
                top++;
                num = (int *)malloc(10 * sizeof(*num));
                num[top-1] = value;
            } else if(top == length) {
                top++;
                num = (int *)realloc(num, (length + length / 2) * sizeof(*num));
                length += length / 2;
                num[top-1] = value;
            } else {
                top++;
                num[top-1] = value;
            }
            continue;
        }
        if(strcmp(s, "get") == 0) {
            int value;
            cin >> value;
            if(value >= top || value < 0) {
                cout << -1 << endl;
            } else cout << num[value] << endl;
            continue;
        }
        if(strcmp(s, "remove") == 0) {
            int value;
            cin >> value;
            int index = 0;
            for(;index < top; ++index)
                if(num[index] == value)
                    break;
            if(index < top) {
                for(;index < top - 1; ++index) {
                    num[index] = num[index+1];
                }
                --top;
            }
        }
    }

    free(num);
    return 0;
}
