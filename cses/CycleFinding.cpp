#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	vector<vector<pair<int,ll> >> side(n+5);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		ll c;cin>>c;
		side[a].push_back({b,c});
	}
	for(int i=1;i<=n;i++){
		side[0].push_back({i,0});
	}
	int cur=0;
	int pre[n+1]={0};
	ll dis[n+1];
	fill(dis,dis+n+1,1e18);
	dis[0]=0;
	for(int i=0;i<=n;i++){
		cur = 0;
		for(int j=0;j<=n;j++){
			for(auto p : side[j]){
				if(dis[p.first]>dis[j]+p.second){
					pre[p.first] = j;
					dis[p.first] = dis[j]+p.second;
					cur = p.first;
				}
			}
		}
	}
	if(cur){
		cout<<"YES\n";
		for(int i=0;i<=n;i++){
			cur = pre[cur];
		}
		int head = cur;
		stack<int> stk;
		while(pre[cur]!=head){
			stk.push(cur);
			cur = pre[cur];
		}
		stk.push(cur);stk.push(pre[cur]);
		while(stk.size()){
			cout<<stk.top()<<" \n"[stk.size()==1];
			stk.pop();
		}
	}else{
		cout<<"NO\n";
	}
	return 0;
}
