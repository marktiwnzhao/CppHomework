//
// Created by marktiwnzhao on 2022/10/19.
//

#include<iostream>
using namespace std;
//链表节点
struct Node{
    Node* next;//前一个节点
    Node* prev;//后一个节点
    int val;//该节点存放的数字
};

//双端队列
struct Deque{
    int size;//有效节点数
    Node* front;//虚拟头节点，不作为有效节点
    Node* rear;//虚拟尾节点，不作为有效节点
};

void push_front (Deque* self, int value);
void push_back (Deque* self, int value);
void pop_front (Deque* self);
void pop_back (Deque* self);
void _delete(const Deque* self);

int main() {
    Deque deque;
    deque.size = 0;
    deque.front = new Node();
    deque.rear = new Node();
    deque.front->prev = nullptr;
    deque.front->next = deque.rear;
    deque.rear->next = nullptr;
    deque.rear->prev = deque.front;

    int n;
    cin >> n;
    string s;
    int val;
    for(int i = 0; i < n; ++i) {
        cin >> s;
        if(s == "pushFront") {
            cin >> val;
            push_front(&deque, val);
            continue;
        }
        if(s == "pushBack") {
            cin >> val;
            push_back(&deque, val);
            continue;
        }
        if(s == "popFront") {
            pop_front(&deque);
            continue;
        }
        if(s == "popBack") {
            pop_back(&deque);
            continue;
        }
        if(s == "getSize") {
            cout << deque.size << endl;
            continue;
        }
    }

    _delete(&deque);
    deque.front->next = nullptr;
    deque.rear->prev = nullptr;
    delete deque.front;
    delete deque.rear;

    return 0;
}

void push_front(Deque* self, int value) {
    self->size++;
    Node* tmp = new Node();
    tmp->val = value;
    tmp->next = self->front->next;
    tmp->prev = self->front;
    self->front->next->prev = tmp;
    self->front->next = tmp;
}

void push_back (Deque* self, int value) {
    self->size++;
    Node* tmp = new Node();
    tmp->val = value;
    tmp->next = self->rear;
    tmp->prev = self->rear->prev;
    self->rear->prev->next = tmp;
    self->rear->prev = tmp;
}

void pop_front (Deque* self) {
    if(self->front->next == self->rear) {
        cout << -1 << endl;
        return;
    }
    self->size--;
    Node* p = self->front->next;
    cout << p->val << endl;
    p->next->prev = self->front;
    self->front->next = p->next;
    delete p;
}

void pop_back (Deque* self) {
    if(self->rear->prev == self->front) {
        cout << -1 << endl;
        return;
    }
    self->size--;
    Node* p = self->rear->prev;
    cout << p->val << endl;
    p->prev->next = self->rear;
    self->rear->prev = p->prev;
    delete p;
}

void _delete (const Deque* self) {
    while(self->front->next != self->rear) {
        Node *p = self->front->next;
        p->next->prev = self->front;
        self->front->next = p->next;
        delete p;
    }
}