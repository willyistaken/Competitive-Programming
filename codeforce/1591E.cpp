#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
struct query{
	int t;
	int l,k;
};
int n,q;
vector<int> cnt;
vector<vector<int> >  side;
vector<int> vton;
vector<int> ans;
vector<vector<query> > onvertex;
vector<int> cntrank;
vector<int> rankcnt;
void add(int num){
	if(rankcnt[num]!=n-1 && cnt[cntrank[rankcnt[num]+1]]==cnt[num]){
		int l = rankcnt[num];
		int r = n;
		while(r-l>1){
			int mid = (l+r)/2;
			if(cnt[cntrank[mid]]==cnt[num]) l=mid;
			else r = mid;
		}
		swap(cntrank[rankcnt[num]],cntrank[l]);
		rankcnt[cntrank[rankcnt[num]]] = rankcnt[num];
		rankcnt[num] = l;
	}
	cnt[num]++;
	return ;
}
void remove(int num){
	if(rankcnt[num]!=0 && cnt[cntrank[rankcnt[num]-1]]==cnt[num]){
		int l = -1;
		int r = rankcnt[num];
		while(r-l>1){
			int mid = (l+r)/2;
			if(cnt[cntrank[mid]]==cnt[num]) r= mid;
			else l = mid;
		}
		swap(cntrank[rankcnt[num]],cntrank[r]);
		rankcnt[cntrank[rankcnt[num]]] = rankcnt[num];
		rankcnt[num] = r;
	}
	cnt[num]--;
}

void dfs(int v){
	add(vton[v]);
	for(auto i : onvertex[v]){
		int l = -1;
		int r = n;
		while(r-l>1){
			int mid = (l+r)/2;
			if(cnt[cntrank[mid]]>=i.l)r = mid;
			else l = mid;
		}
		if(r+i.k-1<n){
			ans[i.t] = cntrank[r+i.k-1];
		}else{
			ans[i.t] = -1;
		}
	}
	for(int u :side[v]){
		dfs(u);
	}
	remove(vton[v]);
}

void solve(){
	cin>>n>>q;
	cnt.resize(n+1);
	side.resize(n+1);
	vton.resize(n+1);
	cntrank.resize(n);
	rankcnt.resize(n+1,0);
	ans.resize(q);
	onvertex.resize(n+1);
	fill(ans.begin(),ans.end(),0);
	fill(cnt.begin(),cnt.end(),0);
	for(int i=0;i<=n;i++) onvertex[i].clear();
	for(int i=0;i<=n;i++) side[i].clear();
	for(int i=0;i<n;i++) cntrank[i] = i+1;
	for(int i=1;i<=n;i++) rankcnt[i] = i-1;
	for(int i=1;i<=n;i++) cin>>vton[i];
	for(int i=2;i<=n;i++){
		int p;cin>>p;
		side[p].push_back(i);
	}
	for(int i=0;i<q;i++){
		int v,l,k;cin>>v>>l>>k;
		query temp = {i,l,k};
		onvertex[v].push_back(temp);
	}
	dfs(1);
	for(int i=0;i<q;i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}
		

	return 0;
}
