#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
typedef long long ll;
char OB[65536]; int OP;
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){static char c;int a;while((c=RC())<'0');a=c^'0';while((c=RC())>='0')a*=10,a+=c^'0';return a;}

int main(){
    int z,xs,xe,ys,ye;
    while(z=R() , z!=0){
        xs=R();xe=R();ys=R();ye=R();
        for(int i=ys;i<=ye;i++){
            for(int j=xs;j<=xe;j++){
                if(__gcd(__gcd(i,j),z)==1) OB[OP++]='*';
                else OB[OP++]='.';
        }
        OB[OP++]='\n';
    }
        OB[OP++]='-';
        OB[OP++]='-';
        OB[OP++]='\n';
        if(OP > 65436) write(1,OB,OP),OP=0;
    } 
    write(1,OB,OP);


    return 0;
}

// 壓常....