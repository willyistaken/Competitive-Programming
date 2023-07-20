#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,s,t;cin>>n>>s>>t;
	vector<ll> arr(n+1);
	for(int i=1;i<=n;i++) cin>>arr[i];
	vector<int> lm(n+1,0);
	vector<int> rm(n+1,0);
	stack<int> stk;
	for(int i=1;i<=n;i++){
		while(stk.size()){
			if(arr[stk.top()]>=arr[i]){
				stk.pop();
			}else break;
		}
		if(stk.size()) lm[i] = stk.top();
		stk.push(i);
	}
	while(stk.size()) stk.pop();
	for(int i=n;i>=1;i--){
		while(stk.size()){
			if(arr[stk.top()]>arr[i]){
				stk.pop();
			}else break;
		}
		if(stk.size()) rm[i] = stk.top();
		stk.push(i);
	}
	vector<int> g(n);
	for(int i=0;i<n;i++) g[i]=i+1;
	sort(g.begin(),g.end(),[&](const int a,const int b){return arr[a]>arr[b];});
	ll dis[n+1];
	for(int i=0;i<=n;i++) dis[i]=1e16;
	dis[s]=0;
	for(auto i : g){
		if(lm[i]) dis[lm[i]] = min(dis[lm[i]],dis[i]+abs(lm[i]-i)*arr[i]);
		if(rm[i]) dis[rm[i]] = min(dis[rm[i]],dis[i]+abs(rm[i]-i)*arr[i]);
	}
	ll ans = LONG_LONG_MAX;
	for(int i=1;i<=n;i++){
		ans= min(ans,dis[i]+abs(i-t)*arr[i]);
	}
	cout<<ans<<"\n";
	return 0;
}
