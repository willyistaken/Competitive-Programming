#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 2e5+5;

int in[N];
int out[N];
vector<int> side[N];
bool vis[N];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;	
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		in[a]++;
		out[b]++;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(min(in[i],out[i])==0){
			q.push(i);	
			vis[i]=1;
		}
	}
	vector<pair<int,int> > ans;
	while(q.size())	{
		int cur = q.front();
		q.pop();
		if(in[cur]) ans.push_back({cur,1});
		else ans.push_back({cur,0});
		for(auto i : side[cur]){
			if(vis[i]) continue;
			if(in[cur]){
				out[i]--;
			}else{
				in[i]--;
			}
			if(min(in[i],out[i])==0){
				q.push(i);
				vis[i]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			cout<<-1<<"\n";
			return 0;
		}
	}
	cout<<ans.size()<<"\n";
	for(int i=(int)ans.size()-1;i>=0;i--){
		cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	}
	return 0;
}
