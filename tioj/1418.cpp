#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
void printb(int k){
	if(k<=0){
		cout<<"oof!";
		return;
	}
	while(k){
		cout<<(k&1);
		k>>=1;
	}
}
int n;
int dp[(1<<22)];
int power[21][21];
int DP(int mask){
	if(mask==0) return 0;
	if(dp[mask]>0) return dp[mask];
	if(dp[mask]<0) return 0;
	int wtp = __lg((mask & -mask));
	int ans = 1e9;
	for(int i=wtp+1;i<n;i++){
		if(!((mask>>i)&1)) continue;
		for(int j=i+1;j<n;j++){
			if(!((mask>>j)&1)) continue;
			int newmask = mask- (1<<wtp) - (1<<i) - (1<<j);
			//cout<<wtp<<" "<<i<<" "<<j<<" : ";
			//printb(mask);cout<<" ";printb(newmask);cout<<"\n";			
			ans = min(ans,power[wtp][i]+power[i][j]+power[j][wtp]+DP(newmask));	
		}
	}
	dp[mask] = (ans)?(ans):(-1);
	return ans;
}

int main(){
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		memset(power,0,sizeof(power));
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++) cin>>power[i][j];
		}
		cout<<DP((1<<(n))-1)<<"\n";
	}
	return 0;
}
