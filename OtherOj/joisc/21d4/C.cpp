#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N =2e5+5;
int H[N];
int C[N];
ll sz[N];
ll sum[N];
vector<int> side[N];
bool vis[N];

void getsize(int cur){
	sz[cur]	=1;
	sum[cur] = C[cur];
	for(auto i : side[cur]){
		getsize(i);
		sz[cur]+=sz[i];
		sum[cur]+=sum[i];
	}
	return ;
}
int n;
//map -H[i], easier
void get(map<int,ll> &s,int cur){
	vis[cur]=1;
	pair<int,int> maxchild = {-1,-1};
	for(int i=0;i<side[cur].size();i++){
		maxchild = max(maxchild,{sz[side[cur][i]],i});
	}
	if(maxchild.second!=-1) get(s,side[cur][maxchild.second]);
	map<int,ll> s2;
	for(int i=0;i<side[cur].size();i++){
		if(i==maxchild.second) continue;
		map<int,ll> os;
		get(os,side[cur][i]);
		for(auto it : os){
			s2[it.first]+=it.second;
		}
	}
	for(auto it : s2){
		s[it.first]+=it.second;
		s[it.first] = min(0LL,s[it.first]);
	}
	s[-H[cur]]-=C[cur];
	ll erasesum = 0;
	while(true){
		auto it = s.upper_bound(-H[cur]);
		if(it==s.end()) break;
		erasesum+=it->second;
		if(erasesum<-C[cur]){
			it->second = erasesum+C[cur];
			break;
		}else{
			s.erase(it);
		}
	}
	return ;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;	
	vector<int> d;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a>>H[i]>>C[i];
		d.push_back(H[i]);
		if(a!=i) side[a].push_back(i);
	}
	sort(d.begin(),d.end());
	d.resize(unique(d.begin(),d.end())-d.begin());
	for(int i=1;i<=n;i++){
		H[i] = lower_bound(d.begin(),d.end(),H[i])-d.begin()+1;
	}

	ll ans=0;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		getsize(i);
		map<int,ll> s;
		get(s,i);
		for(auto it : s){
			ans+=it.second;
		}
		ans+=sum[i];
	}
	cout<<ans<<"\n";
				

	return 0;
}
