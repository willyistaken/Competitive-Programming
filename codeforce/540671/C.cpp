#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 1e5+5;
vector<int> side[N];
int arr[N];
int maxn[N];
void dfs(int c){
	maxn[c]=1;
	int r = 0;
	for(auto i : side[c]){
		if(!maxn[i]){
			dfs(i);
			r= max(r,maxn[i]);
		}
	}
	maxn[c]+=r;
}

bool mark[N];
int cycle(int f){
	mark[f]=1;
	if(mark[arr[f]]) return arr[f];
	return cycle(arr[f]);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=1;i<=n;i++){
		if(arr[i]<=n){
			side[arr[i]].push_back(i);
		}
	}
	vector<int> ans(n+1,0);
	for(int i=1;i<=n;i++){
		if(arr[i]>n){
			dfs(i);
			ans[arr[i]-n] = max(ans[arr[i]-n],maxn[i]);
		}
	}
	
	int rans = 0;
	for(int i=1;i<=n;i++) rans+=ans[i];
	for(int i=1;i<=n;i++){
		if(!mark[i] && !maxn[i]){
			int c = cycle(i);
			int cur = arr[c];
			rans++;
			while(cur!=i){
				rans++;
				cur = arr[cur];
			}
			dfs(c);
		}
	}
	cout<<rans<<"\n";
	return 0;
}
