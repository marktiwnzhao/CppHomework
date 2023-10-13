//
// Created by marktiwnzhao on 2022/11/9.
//
#include <iostream>
#include <vector>

using namespace std;
vector<vector<string>> Sort(vector<vector<string>> floor, int& high, int maxLen);
int main() {
    vector<vector<string>> floor(100);
    int N;
    cin >> N;
    string s;
    int high = 0;
    int maxOfLen = 0;
    for(int i = 0; i < N; i++) {
        cin >> s;
        if(s == "add") {
            cin >> s;
            int len = s.size() / 2 - 1;
            if(len > maxOfLen) maxOfLen = len;
            floor[high].push_back(s);
            high++;
        } else if(s == "del") {
            cin >> s;
            for(int j = 0; j < high; ++j) {
                if(floor[j][0] == s) {
                    floor.erase(floor.cbegin()+j);
                    break;
                }
            }
        } else if(s == "print") {
            floor = Sort(floor, high, maxOfLen);
            for(int j = 0; j < high; ++j) {
                for(int k = 0; k < floor[j].size(); ++k) {
                    if(k == 0) cout << floor[j][0];
                    else cout << floor[j][k].substr(2);
                }
                cout << endl;
            }
        }
    }

    return 0;
}

vector<vector<string>> Sort(vector<vector<string>> floor, int& high, int maxLen) {
    vector<vector<string>> res(100);
    int loc = 0;
    int len;
    for(int i = 0; i < high; i++) {
        len = floor[i][0].size() / 2 - 1;
        int lenLine = 0;
        for(int j = 0; j < res[loc].size(); ++j) {
            lenLine += res[loc][j].size() / 2 - 1;
        }
        if(len + lenLine > maxLen) loc++;
        res[loc].push_back(floor[i][0]);
    }
    loc++;
    high = loc;
    for(int i = 0; i < loc; i++) {
        len = 0;
        for(int j = 0; j < res[i].size(); ++j) {
            len += res[i][j].size() / 2 - 1;
        }
        if(len < maxLen) {
            string s = "0x";
            for (int j = 0; j < 2*(maxLen - len); j++) {
                s += "C";
            }
            res[i].push_back(s);
        }
    }
    return res;
}
