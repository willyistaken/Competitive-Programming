#pragma GCC optimize("O3")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n,M;
#define mask bitset<305> 

bool e[305][305];
int v[305];
void getcon(int cur,mask &m,bool c,mask &in){
	m[cur]=1;
	for(int i=1;i<=n;i++){
		if(!in[i]) continue;
		if(e[cur][i]!=c) continue;
		if(m[i]) continue;
		getcon(i,m,c,in);
	}
}

pair<mask,int> maxdis(mask m,bool c);

pair<mask,int> maxclique(mask m,bool c){
	if(m.count()==1){
		return {m,v[m._Find_first()]};
	}
	pair<mask,int> ans;
	ans.second=0;
	for(int i=1;i<=n;i++){
		if(m[i]){
			mask k;
			getcon(i,k,!c,m);
			auto p  = maxdis(k,!c);
			ans.second+=p.second;
			ans.first|=p.first;
			k.flip();
			m&=(k);
		}
	}
	return ans;
}

pair<mask,int> maxdis(mask m,bool c){
	if(m.count()==1){
		return {m,v[m._Find_first()]};
	}
	pair<mask,int> ans;
	ans.second=0;
	for(int i=1;i<=n;i++){
		if(m[i]){
			mask k;
			getcon(i,k,!c,m);
			auto p = maxclique(k,!c);
			if(ans.second<p.second){
				ans = p;
			}
			k.flip();
			m&=(k);
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>M;	
	for(int i=1;i<=n;i++) cin>>v[i];
	for(int i=0;i<M;i++){
		int a,b;cin>>a>>b;
		e[a][b]=1;
		e[b][a]=1;
	}
	mask in;
	in.set();
	pair<mask,int> ans;
	ans.second=0;
	for(int i=1;i<=n;i++){
		if(in[i]==1){
			mask k;
			getcon(i,k,1,in);
			auto p = maxclique(k,1);
			if(ans.second<p.second){
				ans = p;
			}
			k.flip();
			in&=(k);
		}
	}
	cout<<ans.second<<"\n";
	cout<<ans.first.count()<<"\n";
	for(int i=1;i<=n;i++){
		if(ans.first[i]) cout<<i<<" ";
	}
	cout<<"\n";
	return 0;
}
