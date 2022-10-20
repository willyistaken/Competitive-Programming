#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::


ll dp[11][12][2];
int n;
vector<int> num;
int g;
vector<int> getnum(){
	int b = n;
	vector<int> result(11);
	for(int i=0;i<11;i++){
		result[i] = b%10;
		b/=10;
	}
	reverse(result.begin(),result.end());
	bool flag=0;
	for(int i=0;i<11;i++){
		if(!flag) g = i;
		if(result[i]) flag=1;
		if(!flag) result[i]=-1;
	}
	return result;
}

ll DP(int p,int cnt,bool pre){
	if(p>10) return cnt;	
	if(dp[p][cnt][pre]) return dp[p][cnt][pre];
	if(pre){
		dp[p][cnt][pre] = 9*DP(p+1,cnt,pre)+DP(p+1,cnt+1,pre);		
	}else{
		dp[p][cnt][pre] = DP(p+1,cnt+(num[p]==0),pre);
		if(num[p]>0) dp[p][cnt][pre] += (num[p]-1)*DP(p+1,cnt,1) + DP(p+1,cnt+(p!=g),1);
	}
	//cout<<p<<" "<<cnt<<" "<<pre<<" "<<dp[p][cnt][pre]<<"\n";
	return dp[p][cnt][pre];
}


ll f(int k){
	if(k<0) return 0;
	if(k<10) return 1;

	n = k;
	memset(dp,0,sizeof(dp));
	num = getnum();
	for(int i=0;i<11;i++) cout<<num[i]<<" ";
	cout<<"\n";
	ll ans = DP(0,0,0);
	return ans;
}


int main(){
	int a,b;
	while(cin>>a>>b){
		if(a>b) swap(a,b);
		cout<<f(b)-f(a-1)<<"\n";
	}
}

