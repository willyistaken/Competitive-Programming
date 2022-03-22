#include <bits/stdc++.h>
using namespace std;

static int s_AllocCount = 0;
static int s_mecount=0;
    void* operator new(size_t size) {
        s_AllocCount++;
        s_mecount+=size;
        //std::cout << "Allocating " << size << "bytes\n";
        return malloc(size);
    }

struct color {
    color(uint16_t x1, uint16_t y1, char c1, uint16_t t1)
        : x(x1), y(y1), c(c1), t(t1) {}
    uint16_t x;
    uint16_t y;
    char c;
    uint16_t t;
};
int main(){
    vector<color> arr;
    for(int i=0;i<10000;i++)
    arr.push_back(color(0,0,0,0));
     std::cout<<"This program allocates memories "<<s_AllocCount<<" times"<<std::endl;
     cout<<s_mecount<<endl;
}
   