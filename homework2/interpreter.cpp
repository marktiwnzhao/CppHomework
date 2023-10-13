//
// Created by marktiwnzhao on 2022/10/4.
//
#include<iostream>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

vector<string> split(const string& str, const string& delim) {
    vector<string> res;
    if("" == str) return res;
    char * strs = new char[str.length() + 1] ;
    strcpy(strs, str.c_str());
    char * d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());
    char *p = strtok(strs, d);
    while(p) {
        string s = p;
        res.push_back(s);
        p = strtok(NULL, d);
    }
    return res;
}

bool isNum(string str) {
    for(int i = 0; i < str.size(); ++i) {
        if(str.at(i) == '-' && str.size() > 1) continue;
        if(str.at(i) > '9' || str.at(i) < '0') return false;
    }
    return true;
}

int main() {
    map<string, int> varMap;
    int n;
    string s;
    cin >> n;
    cin >> ws;
    for(int i = 0; i < n; ++i) {
        getline(cin, s);
        vector<string> res = split(s, " ");
        if(res.size() == 2) {
            if(varMap.find(res[1]) == varMap.end()) {
                cout << "error" << endl;
                return 0;
            } else {
                cout << varMap[res[1]] << endl;
                continue;
            }
        }
        if(res.size() == 3) {
            if(isNum(res[2])) varMap[res[0]] = stoi(res[2]);
            else if(varMap.find(res[2]) == varMap.end()) {
                cout << "error" << endl;
                return 0;
            } else varMap[res[0]] = varMap[res[2]];
        }
        if(res.size() == 5) {
            int a, b;
            if(isNum(res[2])) a = stoi(res[2]);
            else if(varMap.find(res[2]) == varMap.end()) {
                cout << "error" << endl;
                return 0;
            } else a = varMap[res[2]];

            if(isNum(res[4])) b = stoi(res[4]);
            else if(varMap.find(res[4]) == varMap.end()) {
                cout << "error" << endl;
                return 0;
            } else b = varMap[res[4]];

            if(res[3] == "+") varMap[res[0]] = a + b;
            if(res[3] == "-") varMap[res[0]] = a - b;
            if(res[3] == "*") varMap[res[0]] = a * b;
            if(res[3] == "/") {
                if(b == 0) {
                    cout << "error" << endl;
                    return 0;
                } else varMap[res[0]] = a * b;
            }
        }
    }

    return 0;
}
