#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 2e5+5;
int f[N][25];
int dep[N];

int lca(int a,int b){
	if(dep[a]>dep[b]) swap(a,b);
	for(int i=24;i>=0;i--){
		if(dep[f[b][i]]>=dep[a]) b= f[b][i];
	}
	if(a==b) return a;
	for(int i=24;i>=0;i--){
		if(f[a][i]!=f[b][i]){
			a = f[a][i];
			b = f[b][i];
		}
	}
	return f[a][0];
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;	
	for(int i=0;i<25;i++) f[1][i]=1;
	for(int i=2;i<=n;i++){
		cin>>f[i][0];
		dep[i] = dep[f[i][0]]+1;
	}
	for(int j=1;j<25;j++){
		for(int i=2;i<=n;i++){
			f[i][j]=  f[f[i][j-1]][j-1];
		}
	}
	while(q--){
		int a,b;cin>>a>>b;
		cout<<lca(a,b)<<"\n";
	}
	return 0;
}
