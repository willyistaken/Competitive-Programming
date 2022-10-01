#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
int n,MOD;

int inv(int a){
	int p = MOD-2;	
	ll r = 1;
	while(p){
		if(p&1) r = (1LL*r*a)%MOD;	
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return (int)r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>MOD;	
	int arr[n][n+1]={0};
	for(int i=0;i<n;i++) cin>>arr[i][n];
	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++) cin>>arr[i][j];
	}
	int wvar[n];
	fill(wvar,wvar+n,-1);
	for(int i=0;i<n;i++){
		int maxn = -1;
		int maxind=-1;
		for(int j=0;j<n;j++){
			if(wvar[j]>=0) continue;	
			if(arr[j][i]>maxn){
				maxn = arr[j][i];
				maxind = j;
			}
		}
		wvar[maxind]=i;
		int multi = inv(arr[maxind][i]);
		for(int k=0;k<=n;k++) arr[maxind][k] = (1LL*arr[maxind][k]*multi)%MOD;
		for(int k=0;k<n;k++){
			if(k==maxind) continue;
			int howm = arr[k][i];
			for(int j=0;j<=n;j++) {
				arr[k][j] = (arr[k][j]-((1LL*howm*arr[maxind][j])%MOD))%MOD;
				if(arr[k][j]<0) arr[k][j]+=MOD;
			}
		}
		
	}
	int ans[n]={0};
	for(int i=0;i<n;i++){
		ans[wvar[i]] = arr[i][n];
	}
	for(int i=0;i<n;i++) cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
}
