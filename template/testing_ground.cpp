#include <bits/stdc++.h>
using namespace std;
int fac[100000]={0};

int fact(int n){
    if(fac[n]) return fac[n];
    fac[n]= n*(fact(n-1));
    return fac[n];
}
int main(){
    fac[0]=1;
    fac[1]=1;
    for(int i=0;i<50;i++){
        cout<<i<<" "<<i<<"!x"<<fact(i)-1<<"!="<<fact(i)<<"!\n";
    }
} 