#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct adj{
	int a,b,k;
};

vector<adj> g;
int x,y,n,m;
void add(vector<ll> &a){
	vector<ll> na(x,0);
	for(auto h : g){
		na[h.b]+=(1LL*h.k*a[h.a])%m;
		na[h.b]%=m;
	}
	a = na;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>x>>y>>n>>m;	
	vector<ll>  sound(x,0);
	for(int i=0;i<y;i++){
		int a,b,k;cin>>a>>b>>k;
		g.push_back({a,b,k});
	}
	for(int i=0;i<x;i++) cin>>sound[i];
	for(int i=0;i<n;i++){
		add(sound);
	}
	for(int i=0;i<x;i++){
		cout<<sound[i]<<"\n";
	}
	return 0;
}
