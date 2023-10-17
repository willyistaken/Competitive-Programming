#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

unordered_set<ll> s;
ll cur = 0;

void add(ll a){
	s.insert(a);
	while(s.count(cur)) cur++;
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	add(0);
	for(int i=1;i<=n;i++){
		int c;cin>>c;
		for(int t=0;t<c;t++){
			ll g = cur;
			while(g<(1LL<<(i+1))){
				add(g);
				g<<=1;
			}
			g>>=1;
			cout<<g<<"\n";
		}
	}
	return 0;
}
