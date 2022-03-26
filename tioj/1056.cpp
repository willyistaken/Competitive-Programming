#include <bits/stdc++.h>
using namespace std;





int main(){
    string a[3];
    for(int i=0;i<3;i++){
        cin>>a[i];
    }
    int o,x=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a[i][j]=='.' | a[i][j]=='O' | a[i][j]=='X'){
                if(a[i][j]=='O') ++o;
                if(a[i][j]=='X') ++x;
            }else{
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    if(o-x==1 || o-x==0){
        cout<<"POSSIBLE\n";
    }else{
        cout<<"IMPOSSIBLE\n";
    }
    return 0;
}