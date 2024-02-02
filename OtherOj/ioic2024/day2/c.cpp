#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


const int N = 2e4+5;
int P[N];
int query(int a){
	if(P[a]==a) return a;
	P[a] = query(P[a]);
	return P[a];
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	vector<vector<int> > ans(m,vector<int>(m));
	vector<pair<int,int> > edge(m);
	for(int i=0;i<m;i++) cin>>edge[i].first>>edge[i].second;
	for(int l = 0;l<m;l++){
		for(int i=1;i<=n;i++) P[i]=i;
		int A = n;
		for(int r=l;r<m;r++){
				if(query(edge[r].first)!=query(edge[r].second))	A--;
				P[query(edge[r].first)]=query(edge[r].second);
				ans[l][r]=A;
		}
	}
	int q;cin>>q;
	int x = 0;
	while(q--){
		int l,r;cin>>l>>r;
		l = (l+x-1)%m+1;
		r = (r+x-1)%m+1;
		if(l>r) swap(l,r);
		cout<<ans[l-1][r-1]<<"\n";
		x = ans[l-1][r-1];
	}
	return 0;
}
