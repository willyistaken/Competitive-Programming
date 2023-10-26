#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define pt pair<pair<int,int>,pair<int,int> >
#define xl first.first
#define xr first.second
#define yl second.first
#define yr second.second
 
const int N = 205;
ll dp[N][N];
string s;
int a,b,c;
int howmany[N][N];
const int MOD = 1e9+7;
int hsh[N];
int ppow[N];
int get(int l,int r){
	ll ans = hsh[r];
	ans = (ans-(1LL*hsh[l-1]*ppow[r-l+1])%MOD)%MOD;
	if(ans<0) ans+=MOD;
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	cin>>s;
	cin>>a>>b>>c;	
	ppow[0]=1;
	for(int i=1;i<=n;i++){
		hsh[i] = (1LL*hsh[i-1]*31)%MOD;
		hsh[i]+=(s[i-1]-'a');
		hsh[i]%=MOD;
		ppow[i] = (31LL*ppow[i-1])%MOD;
	}
	for(int i=0;i<=n+1;i++){
		for(int j=i;j<=n+1;j++) dp[i][j]=1LL*(j-i+1)*a+b;
	}
	for(int l=0;l<n;l++){
		for(int i=1;i+l<=n;i++){
			for(int l2=0;l2<n;l2++){
				for(int j=1;j+l2<=n;j++){
					if(l2<l){howmany[j][j+l2]=0;continue;}
					if(l2==l){
						howmany[j][j+l2] = (get(i,i+l)==get(j,j+l));
					}else{
						if(get(i,i+l)==get(j,j+l)) howmany[j][j+l2] = 1+howmany[j+l+1][j+l2];
						else howmany[j][j+l2] = howmany[j+1][j+l2];
						int k = (l2+1)-(1LL*howmany[j][j+l2]*(l+1));
						dp[j][j+l2] = min(dp[j][j+l2],dp[i][i+l]+(1LL*howmany[j][j+l2]*c)+(1LL*a*k)+b);
					}
				}
			}
//			cout<<dp[i][i+l]<<" ";
		}
		//cout<<"\n";
	}
	cout<<dp[1][n]-b<<"\n";
	return 0;
}
