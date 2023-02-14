#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N  = 1e5+5;
int type[N];
vector<int> side[N];


bool dfs(int cur,int p){
	if(type[cur]) return 1;
	type[cur] = 3-type[p];			
	bool work = 1;
	for(auto i : side[cur]){
		if(!type[i]) work&=dfs(i,cur);
		else if(type[i]==type[cur]) return 0;
	}
	return work;
}
const int MOD = 1e9+7;

int pow(int p){
	ll r = 1;
	ll a = 2;
	while(p){
		if(p&1) r = (r*a)%MOD;
		a = (a*a)%MOD;
		p>>=1;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	int cnt = -1;
	type[0]=2;
	for(int i=1;i<=n;i++){
		if(!type[i]){
			if(!dfs(i,0)){
				cout<<0<<"\n";
				return 0;
			}
			cnt++;
		}
	}
	cout<<pow(cnt)<<"\n";
	return 0;
}
