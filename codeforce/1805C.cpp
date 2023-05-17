#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int n,m;cin>>n>>m;
	vector<int> k(n);
	for(int i=0;i<n;i++){
		cin>>k[i];
	}
	sort(k.begin(),k.end());
	for(int i=0;i<m;i++){
		ll a,b,c;cin>>a>>b>>c;
		int g = lower_bound(k.begin(),k.end(),b)-k.begin();
		if(g!=0){
			if((b-k[g-1])*(b-k[g-1])<4*a*c){
				cout<<"Yes\n";
				cout<<k[g-1]<<"\n";
				continue;
			}
		}
		if(g!=n){
			if((b-k[g])*(b-k[g])<4*a*c)	{
				cout<<"Yes\n";
				cout<<k[g]<<"\n";
				continue;
			}
		}
		cout<<"NO\n";
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
