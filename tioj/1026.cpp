#include <bits/stdc++.h>
using namespace std;
const int tab32[32] = {
     0,  9,  1, 10, 13, 21,  2, 29,
    11, 14, 16, 18, 22, 25,  3, 30,
     8, 12, 20, 28, 15, 17, 24,  7,
    19, 27, 23,  6, 26,  5,  4, 31};

int log2_32 (uint32_t value)
{
    value |= value >> 1;
    value |= value >> 2;
    value |= value >> 4;
    value |= value >> 8;
    value |= value >> 16;
    return tab32[(uint32_t)(value*0x07C4ACDD) >> 27];
}
int main(){
    
    int n;cin>>n;
    //int j=log2_32(n)+1;
    //int m=(((1<<log2_32(n)+1)-n)>>1);
    cout<<log2_32(n)+1<<endl;
    for(int i=0;i<log2_32(n)+1;i++){
        if((((1<<i)&(((1<<log2_32(n)+1)-n)>>1))>>i==1)){
            cout<<'-';
        }else{
            cout<<'+';
        }
    }
    cout<<endl;
    return 0;
    
}