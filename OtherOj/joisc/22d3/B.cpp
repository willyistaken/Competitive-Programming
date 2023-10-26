#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 2e5+5;
int ans[N];
const int D = 42;
int app[N][D];
vector<int> side[N];
int L = 0;
int p[N];
int n;
void dfs(int cur){
	for(auto i : side[cur]){
		if(!p[i]){
			p[i]=cur;
			dfs(i);
		}
	}
}
void debug(){
	cout<<"\n\n\n";
	for(int i=1;i<=n;i++){
		for(int j=0;j<(min(D,n+1));j++){
			cout<<app[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n\n\n";
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>L;
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		for(int d=0;d<D;d++) app[i][d]=1;
		int a;cin>>a;
		ans[i]=a;
	}
	p[1]=1;
	dfs(1);
	//for(int i=1;i<=n;i++) cout<<p[i]<<" ";
	//cout<<"p\n";
	int Q;cin>>Q;
	while(Q--){
		int t; cin>>t;
		if(t==1){
			int x,d,w;cin>>x>>d>>w;	
			int i = 0;
			for(;i<=d && x!=1;i++,x=p[x]){
				app[x][d-i] = (1LL*app[x][d-i]*w)%L;
				if(d-i>0) app[x][d-i-1] = (1LL*app[x][d-i-1]*w)%L;
			}
			for(;i<=d;i++) app[x][d-i] = (1LL*app[x][d-i]*w)%L;
			//debug();
		}else{
			int x;cin>>x;
			int rans = ans[x];
			bool works = 0;
			for(int i=0;i<=40;i++){
				if(works==1) break;
				if(x==1) works=1;
				rans = (1LL*rans*app[x][i])%L;
				x = p[x];
			}
			cout<<rans<<"\n";
		}
	}
	return 0;
}
