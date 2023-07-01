#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<int> side[2005];
int p[2005];
int cnt[2005];
bool incircle[2005];
int bot ;
int top ;
void clean(int n){
    for(int i=1;i<=n;i++) {
		p[i] = 0;
		incircle[i] = 0;
	}
	bot = 0;
	top = 0;
}

void dfs(int cur){
	if(bot) return;
	for(auto i : side[cur]) cnt[i]--;
	//cout<<top<<" "<<cur<<" "<<p[cur]<<" "<<cnt[top]<<"\n";
	for(auto i : side[cur]){
		if(bot) return;
		if(p[cur]!=top && i==top){
			if(cnt[i]>=2){bot=cur;return;}
		}else if(!p[i] && i!=top){
			p[i] = cur;
			dfs(i);
		}
	}
	for(auto i : side[cur]) cnt[i]++;
}
void solve(){
	int n,m;cin>>n>>m;
	for(int i=0;i<=n;i++) side[i].clear();
	for(int i=0;i<=n;i++) cnt[i]=0;
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
		cnt[a]++;
		cnt[b]++;
	}
	for(int i=1;i<=n;i++){
		clean(n);
		top = i;
		dfs(i);
		
		if(bot){
			cout<<"Yes\n";
			//cout<<top<<" "<<bot<<"\n";
			vector<int> ans;
			int head = bot;
			while(head!=i){
				incircle[head] = 1;
				ans.push_back(head)	;
				head = p[head];
			}
			pair<int,int> tail = {0,0};
			for(auto k : side[i]){
				if(!incircle[k] && tail.first)  tail.second = k;
				else if(!incircle[k]) tail.first = k;
			}
			int f = ans.size();
			cout<<f+3<<"\n";
			for(int j=0;j<f-1;j++) {
				cout<<ans[j]<<" "<<ans[j+1]<<"\n";
			}
			cout<<ans[f-1]<<" "<<i<<"\n";
			cout<<bot<<" "<<i<<"\n";
			cout<<i<<" "<<tail.first<<"\n";
			cout<<i<<" "<<tail.second<<"\n";
			return;
		}
	}
	cout<<"No\n";
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
