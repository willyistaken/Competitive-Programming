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
int main(){
    const unsigned int n=1000;
    vector<vector<bitset<3> > > traveled(n,vector<bitset<3> >(n));
     std::cout<<"This program allocates memories "<<s_AllocCount<<" times"<<std::endl;
     cout<<s_mecount<<endl;
}
   