#include <bits/stdc++.h>
using namespace std;

int main(){
    int v,a,b,c;cin>>v>>a>>b>>c;
    v=v%(a+b+c);
    char temp[3]={'F','M','T'};
    int inta[3]={a,b,c};
    for(int i=0;i<3;i++){
        if(v-inta[i]<0){
            cout<<temp[i]<<endl;
            return 0;
        }
        v-=inta[i];
    }
}