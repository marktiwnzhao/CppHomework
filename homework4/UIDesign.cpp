//
// Created by marktiwnzhao on 2022/11/9.
//
#include <iostream>
#include <vector>
/*
 * strcmp与string重载的<都是以字典序来比
 * 而这里是P100与P29:非字典序
 * string转char*:s.c_str()
 * 以上得到的是const char*
 * 要赋值得用strcpy进行复制:char *strcpy(char *dest, const char *src)
 * string子串s.substr(下标, 长度)
 * char*转int:
 * int atoi(const char *nptr);
 * atoi(P100) = 0, atoi(100) = 100;
 */

using namespace std;
struct RGB{
    int X;
    int Y;
    int Z;
};
enum Type{Normal = -1, Single, Reverse};

class Rectangle {
private:
    string polygonid;
    double gray{0.0};
    RGB rgb{0, 0, 0};
    Type type{Normal};
    friend class Plane;
public:
    Rectangle(string type, string p): polygonid(p) {
        if(type == "normal") this->type = Normal;
        else if(type == "single") {
            this->type = Single;
        }
        else this->type = Reverse;
    }

    void setRgb(int X, int Y, int Z) {
        switch (type) {
            case Normal:
                rgb.X = X; rgb.Y = Y; rgb.Z = Z;
                break;
            case Single:
                rgb.X = X; rgb.Y = 0; rgb.Z = 0;
                break;
            case Reverse:
                rgb.X = 255-X; rgb.Y = 255-Y; rgb.Z = 255-Z;
                break;
        }
        gray = rgb.X*0.299 + rgb.Y*0.587 + rgb.Z*0.114;
    }
};


class Group {
private:
    string groupid;
    int size;
    vector<Rectangle*> members;
    friend class Plane;
public:
    Group(int N) : size(N){}

    void setGroupId(string p) {
        groupid = p;
    }
    void addMember(Rectangle* rectangle) {
        members.push_back(rectangle);
    }
    void setGroupRgb(int X, int Y, int Z) {
        for(int i = 0; i < size; ++i) {
            members[i]->setRgb(X, Y, Z);
        }
    }
};

class Plane {
private:
    vector<Rectangle*> allRect;
    int numOfRect{0};
    vector<Group*> allGroup;
    int numOfGroup{0};
public:
    ~Plane();
    void addRect(string type, string p);
    void addGroup(Group* p) {
        allGroup.push_back(p);
        numOfGroup++;
    }
    void Set(string index, int X, int Y, int Z);
    void Print(string s);
    Rectangle* searchRect(string p);
    Group* searchGroup(string g);
};
Plane::~Plane() {
    for(int i = 0; i < numOfRect; i++) {
        delete allRect[i];
    }
    for(int i = 0; i < numOfGroup; i++) {
        delete allGroup[i];
    }
}
void Plane::addRect(string type, string p) {
    Rectangle* tmp = new Rectangle(type, p);
    int i = 0;
    for(; i < numOfRect; ++i) {
        if(atoi(p.substr(1).c_str()) < atoi(allRect[i]->polygonid.substr(1).c_str())) break;
    }
    allRect.insert(allRect.cbegin()+i, tmp);
    numOfRect++;
}

void Plane::Set(string index, int X, int Y, int Z) {
    if(index[0] == 'P') {
        Rectangle* rect = searchRect(index);
        rect->setRgb(X, Y, Z);
    } else {
        Group* group = searchGroup(index);
        group->setGroupRgb(X, Y, Z);
    }
}
Rectangle* Plane::searchRect(string p) {
    for(int i = 0; i < numOfRect; ++i) {
        if(allRect[i]->polygonid == p)
            return allRect[i];
    }
    return nullptr;
}
Group* Plane::searchGroup(string g) {
    for(int i = 0; i < numOfGroup; ++i) {
        if(allGroup[i]->groupid == g) {
            return allGroup[i];
        }
    }
    return nullptr;
}
void Plane::Print(string s) {
    if(s == "Normal") {
        for(int i = 0; i < numOfRect; ++i) {
            cout << allRect[i]->polygonid << " ";
            cout << allRect[i]->rgb.X << " ";
            cout << allRect[i]->rgb.Y << " ";
            cout << allRect[i]->rgb.Z << endl;
        }
    } else {
        int count = numOfRect;
        for(int i = 0; i < count-1; i++) {
            Rectangle* k = allRect[0];
            int index = 0;
            for(int j = 1; j < numOfRect; ++j) {
                if(k->gray > allRect[j]->gray) {
                    k = allRect[j];
                    index = j;
                } else if(k->gray == allRect[j]->gray) {
                    if(atoi(k->polygonid.substr(1).c_str()) > atoi(allRect[j]->polygonid.substr(1).c_str())) {
                        k = allRect[j];
                        index = j;
                    }
                }
            }
            cout << k->polygonid << " ";
            cout << k->rgb.X << " ";
            cout << k->rgb.Y << " ";
            cout << k->rgb.Z << endl;
            delete k;
            allRect.erase(allRect.cbegin()+index);
            numOfRect--;
        }
        cout << allRect[0]->polygonid << " ";
        cout << allRect[0]->rgb.X << " ";
        cout << allRect[0]->rgb.Y << " ";
        cout << allRect[0]->rgb.Z << endl;
    }
}


int main() {
    Plane plane;
    int N = 0;
    cin >> N;
    string op;
    for(int i = 0; i < N; ++i) {
        cin >> op;
        if(op == "Add") {
            string type;
            cin >> type;
            string p;
            cin >> p;
            plane.addRect(type, p);
        } else if(op == "Group") {
            int n;
            cin >> n;
            Group* group = new Group(n);
            string g;
            for(int j = 0; j < n; ++j) {
                cin >> g;
                group->addMember(plane.searchRect(g));
            }
            cin >> g;
            group->setGroupId(g);
            plane.addGroup(group);
        } else if(op == "Set") {
            string index;
            int X, Y, Z;
            cin >> index >> X >> Y >> Z;
            plane.Set(index, X, Y, Z);
        }
    }
    cin >> op;
    plane.Print(op);
}

