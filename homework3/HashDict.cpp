//
// Created by marktiwnzhao on 2022/10/20.
//
#include<iostream>
using namespace std;

struct Node{
    int key;
    string value;
    Node* next;
};

const int MAX_SIZE = 1000;

void add(Node* p, Node* tmp, int pos);
void del(Node* p, int len, int key);

int mod(int len, int key) {
    int tmp = key % len;
    int t = ((3 * tmp * tmp * tmp) % len + (5 * tmp * tmp) % len + (7 * tmp) % len + 11 % len) % len;
    return t < 0 ? -t : t;
}

int main() {
    int len;
    int count = 0;
    cin >> len;
    Node entry[MAX_SIZE];
    for(int i = 0; i < len; ++i) {
        entry[i].key = 0;
        entry[i].value = "";
        entry[i].next = nullptr;
    }

    int n;
    cin >> n;
    int key;
    int pos;
    string s, value;
    bool isExpand;
    for(int i = 0; i < n; ++i) {
        cin >> s;
        if(s == "add") {
            cin >> key;
            cin >> value;
            count++;
            pos = mod(len, key);
            Node* tmp = new Node;
            tmp->key = key;
            tmp->value = value;
            tmp->next = nullptr;
            add(entry, tmp, pos);
        } else if(s == "delete") {
            cin >> key;
            count--;
            del(entry, len, key);
            continue;
        } else if(s == "search") {
            cin >> pos;
            if(entry[pos].next == nullptr) {
                cout << "null" << endl;
                continue;
            }
            Node* p = entry[pos].next;
            cout << p->key << ":" << p->value;
            p = p->next;
            while(p) {
                cout << "->";
                cout << p->key << ":" << p->value;
                p = p->next;
            }
            cout << endl;
        }
        isExpand = ((entry[pos].key > 4) || count > len);
        while(isExpand) {
            isExpand = false;
            int p_len = len;
            len = len*2 + 1;
            Node tmp[MAX_SIZE];
            for(int i = 0; i < len; ++i) {
                tmp[i].key = 0;
                tmp[i].value = "";
                tmp[i].next = nullptr;
            }
            for(int i = 0; i < p_len; ++i) {
                Node* t;
                while(entry[i].next) {
                    int pos = mod(len, entry[i].next->key);
                    t = entry[i].next->next;
                    add(tmp, entry[i].next, pos);
                    entry[i].next = t;
                }
            }
            for(int i = 0; i < len; ++i) {
                entry[i] = tmp[i];
                if(entry[i].key > 4) isExpand = true;
            }
        }
    }
    for(int i = 0; i < len; ++i) {
        Node* p = entry[i].next;
        while(p) {
            entry[i].next = p->next;
            delete p;
            p = entry[i].next;
        }
    }
    return 0;
}

void add(Node* p, Node* tmp, int pos) {
    p[pos].key++;
    Node* ins = p[pos].next;
    if(!ins) {
        p[pos].next = tmp;
        tmp->next = nullptr;
        return;
    }
    if(tmp->key < ins->key) {
        p[pos].next = tmp;
        tmp->next = ins;
        return;
    }
    while(ins->next) {
        if(ins->next->key > tmp->key) break;
        ins = ins->next;
    }
    tmp->next = ins->next;
    ins->next = tmp;
}


void del(Node* p, int len, int key) {
    int pos = mod(len, key);
    p[pos].key--;
    Node* tmp = p + pos;
    while(tmp->next) {
        if(tmp->next->key == key) {
            break;
        }
        tmp = tmp->next;
    }
    Node* k = tmp->next;
    tmp->next = k->next;
    delete k;
}











Node* expand(Node* p, int& len) {
    int p_len = len;
    len = len*2 + 1;
    Node* tmp = new Node[MAX_SIZE];
    for(int i = 0; i < MAX_SIZE; ++i) {
        tmp[i].key = 0;
        tmp[i].value = "";
        tmp[i].next = nullptr;
    }
    for(int i = 0; i < p_len; ++i) {
        Node* t;
        while(p[i].next) {
            int pos = mod(len, p[i].next->key);
            t = p[i].next->next;
            add(tmp, p[i].next, pos);
            p[i].next = t;
        }
    }
    for(int i = 0; i < MAX_SIZE; ++i) {
        delete (p + i);
    }
    return tmp;
}