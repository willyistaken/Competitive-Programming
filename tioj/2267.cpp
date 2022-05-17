#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    string s;cin>>s;
    if(n==1){
        cout<<"Yes\n";
        return 0;
    }
    if(n==2 ){
        if(s[0]!=s[1]){
            cout<<"No\n";  
        }else{
            cout<<"Yes\n";
        }
        return 0;
    }
    if(n%3==2){
        bool xo = (s[0]=='1');
        for(int i=1;i<n;i++){
            if(i%3!=2){
                xo^=(s[i]=='1');
            }
        }
        if(xo){
            cout<<"No\n";
        }else{
            cout<<"Yes\n";
        }
    }else{
        cout<<"Yes\n";
    }

//the solution by npsc is wrong?(it should be xor == 1 → no)
    return 0;
}