//
// Created by marktiwnzhao on 2022/12/16.
//
#include<iostream>
#include <vector>

using namespace std;
class Car {
    int Speed;
    int Limit;
public:
    int Change;
    int Road;
    int Place;
    bool isBlocked{false};
    Car(int R, int P, int S, int L, int C):Speed(S), Limit(L), Change(C), Road(R), Place(P) {}
    void SpeedUp() {
        if(Speed + 10 <= Limit) Speed += 10;
    }
    int MoveDis() {
        return Speed;
    }
    void setSpeed(int speed) {
        Speed = speed;
    }
};
void Insert(vector<Car*>& r, Car* t) {
    int i = 0;
    for(; i < r.size() && r[i]->Place < t->Place; ++i) {}
    r.insert(r.cbegin()+i, t);
}
int main() {
    int T, N;
    cin >> T >> N;
    vector<Car*> p(N);
    int R, P, S, L, C;
    for(int i = 0; i < N; i++) {
        cin >> R >> P >> S >> L >> C;
        p[i] = new Car(R, P, S, L, C);
    }
    vector<Car*> Road1;
    vector<Car*> Road2;
    vector<Car*> Road3;
    for(int i = 0; i < N; ++i) {
        if(p[i]->Road == 1) {
            Insert(Road1, p[i]);
        } else if(p[i]->Road == 2) {
            Insert(Road2, p[i]);
        } else {
            Insert(Road3, p[i]);
        }
    }

    bool isPlace;
    for(int i = 0; i < T; ++i) {
        //变道
        for(int j = 0; j < Road1.size(); ++j) {
            isPlace = false;
            if(Road1[j]->isBlocked) {
                Road1[j]->isBlocked = false;
                if(Road1[j]->Change == 3) {
                    for(int k = 0; k < Road2.size(); ++k) {
                        if (Road2[k]->Place == Road1[j]->Place) {
                            isPlace = true;
                            break;
                        }
                    }
                    if (!isPlace) {
                        Insert(Road2, Road1[j]);
                        Road1[j]->Road = 2;
                        Road1.erase(Road1.cbegin() + j);
                        --j;
                    }
                }
            }
        }
        for(int j = 0; j < Road2.size(); ++j) {
            isPlace = false;
            if(Road2[j]->isBlocked) {
                Road2[j]->isBlocked = false;
                if(Road2[j]->Change == 2) {
                    for(int k = 0; k < Road1.size(); ++k) {
                        if(Road1[k]->Place == Road2[j]->Place) {
                            isPlace = true;
                            break;
                        }
                    }
                    if(!isPlace) {
                        Insert(Road1, Road2[j]);
                        Road2[j]->Road = 1;
                        Road2.erase(Road2.cbegin()+j);
                        --j;
                    }
                } else if(Road2[j]->Change == 3) {
                    for(int k = 0; k < Road3.size(); ++k) {
                        if(Road3[k]->Place == Road2[j]->Place) {
                            isPlace = true;
                            break;
                        }
                    }
                    if(!isPlace) {
                        Insert(Road3, Road2[j]);
                        Road2[j]->Road = 3;
                        Road2.erase(Road2.cbegin()+j);
                        --j;
                    }
                }
            }
        }
        for(int j = 0; j < Road3.size(); ++j) {
            isPlace = false;
            if(Road3[j]->isBlocked) {
                Road3[j]->isBlocked = false;
                if(Road3[j]->Change == 2) {
                    for(int k = 0; k < Road2.size(); ++k) {
                        if(Road2[k]->Place == Road3[j]->Place) {
                            isPlace = true;
                            break;
                        }
                    }
                    if(!isPlace) {
                        Insert(Road2, Road3[j]);
                        Road3[j]->Road = 2;
                        Road3.erase(Road3.cbegin() + j);
                        --j;
                    }
                }
            }
        }
        //加速
        for(int j = 0; j < N; ++j) {
            p[j]->SpeedUp();
        }
        //移动
        for(int j = Road1.size()-1; j >= 0; --j) {
            if(j == Road1.size()-1) {
                Road1[j]->Place += Road1[j]->MoveDis();
            } else {
                if(Road1[j]->Place + Road1[j]->MoveDis() >= Road1[j+1]->Place) {
                    Road1[j]->Place = Road1[j+1]->Place - 10;
                    Road1[j]->setSpeed(Road1[j+1]->MoveDis());
                    Road1[j]->isBlocked = true;
                } else Road1[j]->Place += Road1[j]->MoveDis();
            }
        }

        for(int j = Road2.size()-1; j >= 0; --j) {
            if(j == Road2.size()-1) {
                Road2[j]->Place += Road2[j]->MoveDis();
            } else {
                if(Road2[j]->Place + Road2[j]->MoveDis() >= Road2[j+1]->Place) {
                    Road2[j]->Place = Road2[j+1]->Place - 10;
                    Road2[j]->setSpeed(Road2[j+1]->MoveDis());
                    Road2[j]->isBlocked = true;
                } else Road2[j]->Place += Road2[j]->MoveDis();
            }
        }

        for(int j = Road3.size()-1; j >= 0; --j) {
            if(j == Road3.size()-1) {
                Road3[j]->Place += Road3[j]->MoveDis();
            } else {
                if(Road3[j]->Place + Road3[j]->MoveDis() >= Road3[j+1]->Place) {
                    Road3[j]->Place = Road3[j+1]->Place - 10;
                    Road3[j]->setSpeed(Road3[j+1]->MoveDis());
                    Road3[j]->isBlocked = true;
                } else Road3[j]->Place += Road3[j]->MoveDis();
            }
        }

    }
    int last = p[0]->Place;
    if(!Road1.empty() && Road1[0]->Place < last) last = Road1[0]->Place;
    if(!Road2.empty() && Road2[0]->Place < last) last = Road2[0]->Place;
    if(!Road3.empty() && Road3[0]->Place < last) last = Road3[0]->Place;
    int first = p[0]->Place;
    if(!Road1.empty() && Road1[Road1.size()-1]->Place > first) first = Road1[Road1.size()-1]->Place;
    if(!Road2.empty() && Road2[Road2.size()-1]->Place > first) first = Road2[Road2.size()-1]->Place;
    if(!Road3.empty() && Road3[Road3.size()-1]->Place > first) first = Road3[Road3.size()-1]->Place;

    cout << first - last << endl;

    for(int i = 0; i < N; ++i) {
        delete p[i];
    }
    return 0;
}

