#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 1e5+5;
int father[N][20];
int dep[N];
ll ans = 0;
int f  = 1;
int s = 1;

int lca(int a,int b){
	if(dep[a]>dep[b]) swap(a,b);
	for(int i=19;i>=0;i--){
		if(dep[father[b][i]]>=dep[a]) b = father[b][i];
	}
	if(a==b) return a;
	for(int i = 19;i>=0;i--){
		if(father[a][i]!=father[b][i]){
			a = father[a][i] ;
			b = father[b][i] ;
		}
	}
	assert(father[a][0]==father[b][0]);
	return father[a][0];
}

void update(int v){
	int l = lca(f,v);	
	int can1 = dep[v]-dep[l]+dep[f]-dep[l];
	int r = lca(s,v);		
	int can2 = dep[v]-dep[r]+dep[s]-dep[r];
	if(max(can1,can2)>ans){
		ans = max(can1,can2);
		if(can1>can2){
			s = v;
		}else{
			f = v;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	dep[1] = 1;
	fill(father[1],father[1]+20,1);
	for(int i = 2;i<=n;i++){
		int p;cin>>p;
		father[i][0] = p;
		dep[i] = dep[p]+1;
		for(int k=1;k<20;k++){
			father[i][k] = father[father[i][k-1]][k-1];
		}
		update(i);
		cout<<ans<<"\n";
	}
	return 0;
}
