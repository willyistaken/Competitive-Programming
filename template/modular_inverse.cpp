#include <bits/stdc++.h>
using namespace std;
//input: n,m output: x such that n*x = 1 mod(m);
int mie(int n,int m,int ns,int nr,int ms,int mr){
    if((n*ms+m*mr)==0) return ns;
    int time= (n*ns+m*nr)/(n*ms+m*mr);
    return mie(n,m,ms,mr,ns-(time*ms),nr-(time*mr));
}
/*
    x satisfy the following equalty "nx + my = gcd(n,m)" in this case gcd(n,m)=1
    in order to get to that we start with (n*1+m*0 = n )and ( n*0+m*1= m ) then use the euclid's algorithm
    after subtracting a bunch of time , we get to nx+my = gcd(n,m) then we can simply return x;

*/
int main(){
    int n,m;cin>>n>>m;
    cout<<mie(n,m,1,0,0,1)+m<<endl;
    cout<<2*500000005<<endl;
}
