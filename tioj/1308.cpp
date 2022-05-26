 #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll H[51][51];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=1;i<=51;i++){
        for(int j=0;j<=51;j++){
            if(i==1){
                H[i][j]=1;
            }else{
                ll ans=0;
                for(int g=0;g<=j;g++){
                    ans+=H[i-1][g];
                }
                H[i][j]=ans;
            }
        }
    }
    int n,m;
    while(cin>>n>>m && n){
        cout<<H[n][m]<<endl;
    }





    return 0;
} 
