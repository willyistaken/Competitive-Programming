#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 1e6+5;
pair<ll,ll> dp[N];
int Bpa[N];
ll Bpasum[N];
int Bpaj[N];
int n,K;

ll cost(int i,int j){
	int r = min(Bpaj[j],j);
	int l = i+1;
	if(r<l) return 0;
	return (1LL*j*(r-l+1))-(Bpasum[r]-Bpasum[l-1]);
}

struct seg{
	int pos;int l;int r;
	seg(int _pos,int _l,int _r):pos(_pos),l(_l),r(_r){}
};

bool ok(ll v){
	for(int i=0;i<=n;i++) dp[i] = {1e18,0};
	dp[0]={0,0};
	dp[n+1] = {1e15,0};
	deque<seg> dq;
	dq.push_back(seg(0,1,n));
	for(int i=1;i<=n;i++){
		while(dq.size()){
			if(dq[0].r<i) dq.pop_front();
			else break;
		}
		dp[i] = {dp[dq[0].pos].first+cost(dq[0].pos,i)+v,dp[dq[0].pos].second+1};
		while(dq.size()){
			if(dp[dq.back().pos].first+cost(dq.back().pos,dq.back().l)>dp[i].first+cost(i,dq.back().l)) dq.pop_back();
			else break;
		}
		if(dq.empty()) dq.push_back(seg(i,i+1,n));
		else{
			seg pseg = dq.back();
			dq.pop_back();
			ll l = pseg.l;ll r = pseg.r+1;
			while(r-l>1){
				ll mid = (l+r)/2;
				if(dp[pseg.pos].first+cost(pseg.pos,mid)>dp[i].first+cost(i,mid)) r=mid;
				else l = mid;
			}
			dq.push_back(seg(pseg.pos,pseg.l,l));
			if(l!=n) dq.push_back(seg(i,l+1,n));
		}
	}
	return (dp[n].second<=K);
}
 
signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>K;			
	string s;cin>>s;
	int pa = 0;
	int pb = 0;
	for(int i=1;i<=2*n;i++){
		if(s[i-1]=='A') Bpaj[pa++]=pb;
		if(s[i-1]=='B') Bpa[++pb]=pa;
	}
	for(int i=pa;i<=n;i++) Bpaj[i]=n;
	for(int i=1;i<=n;i++){
		Bpasum[i] = Bpasum[i-1]+Bpa[i];
	}
	ll l = -1;ll r = 1LL*n*n+2;
	while(r-l>1){
		ll mid = l+((r-l)/2);
		if(ok(mid)) r = mid;
		else l = mid;
	}
	ok(r);
	//cout<<r<<"\n";
	cout<<dp[n].first-(1LL*r*K)<<"\n";
 
	return 0;
}
