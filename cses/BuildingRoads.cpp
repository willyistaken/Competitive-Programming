#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


vector<int> p;

int query(int a){
	return (p[a] = (p[a]==a)?(p[a]):(query(p[a])));
}

void join(int a,int b){
	p[query(a)] = query(b);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	p.resize(n+1);
	for(int i=0;i<=n;i++) p[i]=i;
	int m;cin>>m;
	while(m--){
		int a,b;cin>>a>>b;
		join(a,b);
	}
	for(int i=0;i<=n;i++) query(i);
	sort(p.begin(),p.end());
	p.resize(unique(p.begin(),p.end())-p.begin());
	cout<<p.size()-2<<"\n";
	for(int i=1;i<p.size()-1;i++){
		cout<<p[i]<<" "<<p[i+1]<<"\n";
	}
	return 0;
}
