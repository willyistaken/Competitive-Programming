#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
int s;
const int MOD = 1e9+7;
struct bit{
	vector<int> arr;
	void init(){
		arr.resize(s+1,0);
	}
	int query(int r){
		ll ans=0;
		while(r){
			ans = (ans+arr[r])%MOD;
			r-=(r & -r);
		}
		return ans;
	}
	void add(int v,int ind){
		v%=MOD;
		while(ind<=s){
			arr[ind] = (arr[ind]+v)%MOD;
			ind+=(ind & -ind);
		}
	}
	void print(){
		for(int i=1;i<=s;i++){
			cout<<query(i)-query(i-1)<<" ";	
		}
		//cout<<"\n";
	}
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;

	vector<int> arr(n,1);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	vector<int> d = arr;
	sort(d.begin(),d.end());
	d.resize(unique(d.begin(),d.end())-d.begin());
	for(int i=0;i<n;i++){
		arr[i] = lower_bound(d.begin(),d.end(),arr[i]) - d.begin();
	}
	s = d.size();
	bit dp0;
	bit dp1;
	dp0.init();dp1.init();
	for(int i=0;i<n;i++){
		int lind = arr[i];
		int rind = s-arr[i]-1;
		int dp1ans = dp0.query(lind)+1;
		int dp0ans = dp1.query(rind)+1;
		//cout<<lind<<" "<<rind<<" ";
		//cout<<dp0ans<<" "<<dp1ans<<"\n";
		dp0.add(dp0ans,lind+1);
		dp1.add(dp1ans,rind+1);
		//dp0.print();
		//cout<<" ";
		//dp1.print();
		//cout<<"\n";
	}
	//cout<<dp0.query(s)<<" "<<dp1.query(s)<<"\n";
	ll ans = (dp0.query(s)+dp1.query(s))%MOD;
	ans=(ans-((2LL*n)%MOD))%MOD;
	ans=(ans-(((1LL*n*n)-(1LL*n))/2)%MOD)%MOD;
	int cnt[s]={0};
	for(int i=0;i<n;i++) cnt[arr[i]]++;
	for(int i=0;i<s;i++){
		ans=(ans +((((1LL*cnt[i]*cnt[i])-(1LL*cnt[i]))/2)%MOD))%MOD;
	}
	if(ans<0) ans+=MOD;
	cout<<ans<<"\n";
	return 0;
}
