#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1000000007;
inline int modadd(int a,int b){
    a%=MOD;
    b%=MOD;
    return (a+b)%MOD;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n,a,b,k;cin>>n>>a>>b>>k;
    int ans[n+1][2]={{0}};
	ans[a][0]=1;
	int sumofprev[n+1] = {0};
    for(int j=0;j<=k;j++){
        for(int i=1;i<=n;i++){
            if(j>0){
				if(i<b){
					ans[i][j%2]=sumofprev[i+(b-i-1)/2]-sumofprev[0];
				}
				if(i>b){
					ans[i][j%2]=sumofprev[n]-sumofprev[i-((i-b-1)/2)-1];
				}
				if(i==b) ans[i][j%2]=0;
            }
			sumofprev[i]=sumofprev[i-1]+ans[i][j%2];
        }
    }
	cout<<sumofprev[n]<<endl;




    return 0;
}
