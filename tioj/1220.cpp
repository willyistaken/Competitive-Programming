#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N=1e5+5;
int p[N];
int sz[N];
vector<int> side[N];
vector<int> pot;
int query(int a){
	if(p[a]==a) return p[a];
	p[a] = query(p[a]);
	return p[a];
}
void join(int a,int b){
	a = query(a); b = query(b);
	if(a==b) return;
	sz[a]+=sz[b];
	p[b]=a;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	vector<int> ord;
	vector<int> cnt(n+1,0);
	for(int i=1;i<=n;i++){
		p[i]=i;
		sz[i]=1;
		ord.push_back(i);
		pot.push_back(i);
	}
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	sort(ord.begin(),ord.end(),[&](const int &a,const int &b){return side[a].size()<side[b].size();});
	for(auto i : ord){
		for(auto v : pot) cnt[v]=0;
		for(auto e : side[i]){
			cnt[query(e)]++;	
		}
		vector<pair<int,int> > jq;
		for(auto v : pot){
			if(cnt[v]<sz[v]){
				jq.push_back({v,i});
			}
		}
		for(auto pa : jq){
			join(pa.first,pa.second);
		}
		vector<int> temp;
		for(auto v : pot){
			if(query(v)==v) temp.push_back(v);
		}
		swap(temp,pot);
		vector<int>(0).swap(temp);
	}
	cout<<pot.size()<<"\n";
	return 0;
}
