#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1000000007;
inline int modadd(int a,int b){
    a%=MOD;
    b%=MOD;
    if((a+b)%MOD<0) return ((a+b)%MOD+MOD);
    return (a+b)%MOD;
} 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n,a,b,k;cin>>n>>a>>b>>k;
    int ans[n+1]={0};
	ans[a]=1;
	int sumofprev[n+1][2] = {{0}};
    for(int j=0;j<=k;j++){
        for(int i=1;i<=n;i++){
            if(j>0){
				if(i<b){
					ans[i]=modadd(modadd(sumofprev[i+(b-i-1)/2][(j+1)%2],-sumofprev[0][(j+1)%2]),-modadd(sumofprev[i][(j+1)%2],-sumofprev[i-1][(j+1)%2]));
				}
				if(i>b){
					ans[i]=modadd(modadd(sumofprev[n][(j+1)%2],-sumofprev[i-(i-b-1)/2-1][(j+1)%2]),-modadd(sumofprev[i][(j+1)%2],-sumofprev[i-1][(j+1)%2]));
				}
				if(i==b) ans[i]=0;
            }
			sumofprev[i][j%2]=modadd(sumofprev[i-1][(j)%2],ans[i]);
        }
    }
	cout<<sumofprev[n][k%2]<<endl;




    return 0;
}
