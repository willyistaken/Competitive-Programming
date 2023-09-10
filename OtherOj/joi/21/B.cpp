#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<ll> minn;
vector<ll> maxn;
vector<ll> loc;

int n,q;
int whichone(ll x){
	if(x>loc[n-1]){
		if(x<=loc[n-1]+maxn[q])	 return n-1;
		return -1;
	}else if(x<=loc[0]){
		if(x>loc[0]-minn[q]) return 0;
		return -1;
	}else{
		int rp = lower_bound(loc.begin(),loc.end(),x)-loc.begin();
		int lp = rp-1;
		int lt = 0;
		int rt = 0;
		if(loc[lp]+maxn[q]<x) lt=-1;
		else lt = lower_bound(maxn.begin(),maxn.end(),x-loc[lp])-maxn.begin();
		if(loc[rp]-minn[q]>=x) rt = -1;
		else rt = upper_bound(minn.begin(),minn.end(),loc[rp]-x)-minn.begin();
		if(lt==-1 && rt==-1) return -1;
		if(lt==-1) return rp;
		if(rt==-1) return lp;
		if(lt<rt) return lp;
		else return rp;
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;	
	loc.resize(n,0);
	minn.resize(q+1,1e18);
	maxn.resize(q+1,-1e18);
	for(int i=0;i<n;i++) cin>>loc[i];
	vector<ll> sum(q+1,0);
	for(int i=1;i<=q;i++){
		cin>>sum[i];
		sum[i]+=sum[i-1];
	}
	minn[0]=0;
	maxn[0]=0;
	for(int i=1;i<=q;i++){
		minn[i] = min(minn[i-1],sum[i]);	
		maxn[i] = max(maxn[i-1],sum[i]);	
	}
	for(int i=1;i<=q;i++) minn[i] = -minn[i];
	for(int i=0;i<n;i++){
		ll ans = 0;
		if(whichone(loc[i])==i){
	  		ll l=0;ll r = minn[q];
			while(r-l>1){
				ll mid = l+((r-l)/2);
				if(whichone(loc[i]-mid)==i) l = mid;
				else r = mid;
			}
			ans+=l+1;
		}
		if(whichone(loc[i]+1)==i){
			ll l = 1;ll r = maxn[q]+1;
			while(r-l>1){
				ll mid=l+((r-l)/2);
				if(whichone(loc[i]+mid)==i) l =mid;
				else r = mid;
			}
			ans+=l;
		}
		cout<<ans<<"\n"	;
	}
			
	
	return 0;
}
