#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1000000007;
int modadd(int a,int b){
    a%=MOD;
    b%=MOD;
    return (a+b)%MOD;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n,a,b,k;cin>>n>>a>>b>>k;
    vector<vector<int> > ans(n+1,vector<int>(k+1,0));
   
    int realans=0;
    for(int j=0;j<=k;j++){
        for(int i=1;i<=n;i++){
            ans[i][j]=0;
            ans[a][0]=1;
            if(j>0){
            for(int g=1;g<=n;g++){
                if(abs(g-i)<abs(b-g) && i!=g){
                    ans[i][j]+=ans[g][j-1];
                    ans[i][j]%=MOD;

                }
            } 
            }
        }
    }
    for(int i=1;i<=n;i++) {
        realans+=ans[i][k];
        realans%=MOD;
    }   
    cout<<realans<<endl;





    return 0;
}