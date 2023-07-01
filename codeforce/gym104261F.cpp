#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<vector<int> > side;
vector<int> child;
void dfs(int cur){
	for(auto i : side[cur]){
		dfs(i);
		child[cur]+=child[i];
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,d;cin>>n>>d;	
	int arr[n];
	int cnt[n];
	side.resize(n);
	child.resize(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++) child[i]=1;
	for(int i=0;i<n;i++) cnt[i]=0;
	
	deque<int>  dq;
	for(int i=0;i<n;i++){
		while(dq.size()){
			if(arr[dq[dq.size()-1]]<arr[i]) dq.pop_back();
			else break;
		}
		if(dq.size()){
			side[dq[dq.size()-1]].push_back(i);
			cnt[i]++;
		}
		dq.push_back(i);
	}
	vector<int> ark;
	for(int i=0;i<n;i++){
		if(!cnt[i]){dfs(i);
		ark.push_back(child[i]);
		}
	}
	sort(ark.begin(),ark.end());
	int k = ark.size();
	ll ans = 0;
	for(int i=1;i<=min(d,k);i++){
		ans+=ark[k-i];
	}
	cout<<ans<<"\n";
	return 0;
}
