//
// Created by marktiwnzhao on 2022/9/15.
//
#include <iostream>
#include <vector>

using namespace std;

class Matrix {
public:
    int height = 0;
    int width = 0;
    vector<vector<int>> vec;

    Matrix();
    vector<vector<int>>* Add(const Matrix* m);
    vector<vector<int>>* Sub(const Matrix* m);
    vector<vector<int>>* Mul(const Matrix* m);
    vector<vector<int>>* Conv(const Matrix* m);
    void Print(const vector<vector<int>>* p, int h, int w);
};
Matrix::Matrix() {
    cin >> height;
    cin >> width;
    for(int i = 0; i < height; ++i) {
        vector<int> row(width);
        for(int j = 0; j < width; ++j) {
            cin >> row[j];
        }
        vec.push_back(row);
    }
}

vector<vector<int>>* Matrix::Add(const Matrix* m) {
    if(height != m->height || width != m->width) {
        return nullptr;
    } else {
        vector<vector<int>>* p = new vector<vector<int>>(height, vector<int>(width));
        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                (*p)[i][j] = vec[i][j] + m->vec[i][j];
            }
        }
        return p;
    }
}

vector<vector<int>>* Matrix::Sub(const Matrix* m) {
    if(height != m->height || width != m->width) {
        return nullptr;
    } else {
        vector<vector<int>>* p = new vector<vector<int>>(height, vector<int>(width));
        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                (*p)[i][j] = vec[i][j] - m->vec[i][j];
            }
        }
        return p;
    }
}

vector<vector<int>>* Matrix::Mul(const Matrix *m) {
    if(height != m->height || width != m->width) {
        return nullptr;
    } else {
        vector<vector<int>>* p = new vector<vector<int>>(height, vector<int>(width));
        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                (*p)[i][j] = vec[i][j] * m->vec[i][j];
            }
        }
        return p;
    }
}

vector<vector<int>>* Matrix::Conv(const Matrix* m) {
    if(height < m->height || width < m->width) {
        return nullptr;
    } else {
        int h = height - m->height + 1;
        int w = width - m->width + 1;
        vector<vector<int>>* p = new vector<vector<int>>(h, vector<int>(w));
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                for(int x = 0; x < m->height; ++x) {
                    for(int y = 0; y < m->width; ++y) {
                        (*p)[i][j] += vec[i+x][j+y] * m->vec[x][y];
                    }
                }
            }
        }
        return p;
    }
}


void Matrix::Print(const vector<vector<int>>* p, int h, int w) {
    if(p == nullptr) {
        cout << "error" << endl;
    } else {
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                cout << (*p)[i][j];
                if(j != w - 1) {
                    cout << ' ';
                }
            }
            cout << endl;
        }
    }
}

int main(){
    int n1;
    cin >> n1;
    Matrix* ms[n1];
    for(int i = 0; i < n1; ++i) {
        ms[i] = new Matrix;//要手动释放内存，这里忘记了
    }
    int n2;
    cin >> n2;
    string s;
    int a, b;
    for(int i = 0; i < n2; ++i) {
        cin >> s;
        cin >> a;
        cin >> b;
        if(s == "add") {
            ms[a]->Print(ms[a]->Add(ms[b]), ms[a]->height, ms[a]->width);
        } else if(s == "sub") {
            ms[a]->Print(ms[a]->Sub(ms[b]), ms[a]->height, ms[a]->width);
        } else if(s == "mul") {
            ms[a]->Print(ms[a]->Mul(ms[b]), ms[a]->height, ms[a]->width);
        } else {
            ms[a]->Print(ms[a]->Conv(ms[b]), ms[a]->height - ms[b]->height + 1, ms[a]->width - ms[b]->width + 1);
        }
    }
    return 0;
}
