//
// Created by marktiwnzhao on 2022/11/29.
//


#include<iostream>
using namespace std;

class CopyTrack
{
public:
    CopyTrack()
    {
        cout << "[CopyTrack::CopyTrack ]" << endl;
    }
    CopyTrack(const CopyTrack &c)
    {
        i = c.i;
        cout << "[CopyTrack::copy-constructor]" << endl;
    }
    ~CopyTrack()
    {
        cout << "[CopyTrack::~CopyTrack]" << endl;
    }
    int i = 0;
};
CopyTrack GetCopy()
{
    return CopyTrack();
}
int main()
{
    CopyTrack c = GetCopy();
    cout << "c.i=" << c.i << endl;
    return 0;
}
