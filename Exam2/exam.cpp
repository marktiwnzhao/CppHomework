//
// Created by marktiwnzhao on 2022/12/4.
//
#include<iostream>
using namespace std;
class Buffer {
    char* buffer;
    int x{0};
    int c;
public:
    Buffer(int C):buffer(new char[C]), c(C) {}
    ~Buffer() {
        delete[] buffer;
    }
    void init() {
        for(int i = 0; i < c; ++i) {
            buffer[i] = '#';
        }
    }
    void getIn(int absno, string s) {
        for(int i = 0; i < s.size(); ++i) {
            if(absno < x) {
                absno++;
                continue;
            }
            if(absno < c) {
                buffer[absno++] = s[i];
            }
        }
        if(x < c && buffer[x] != '#') {
            cout << x+1 << " ";
            while(x < c && buffer[x] != '#') {
                cout << buffer[x];
                buffer[x] = '#';
                ++x;
            }
        } else {
            cout << 0 << " " << "null";
        }
    }
    void getOut() {
        cout << " ";
        for(int i = 0; i < c; ++i) {
            cout << buffer[i];
        }
        cout << endl;
    }
};
int main() {
    int N, C, ISN, L;
    cin >> N >> C >> ISN >> L;
    Buffer buffer(C);
    buffer.init();
    int seqno;
    string s;
    bool isOverflow = false;
    for(int i = 0; i < N; ++i) {
        cin >> seqno;
        cin >> s;
        if(seqno-ISN < 0) isOverflow = true;
        if(isOverflow && seqno-ISN < 0) seqno += L;
        buffer.getIn(seqno-ISN, s);
        buffer.getOut();
    }
    return 0;
}
