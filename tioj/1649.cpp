#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,h;
vector<ll> damage;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>h;
	damage.resize(n);
	ll maxn=0;	
	for(int i=0;i<n;i++){
		cin>>damage[i];
		maxn = max(damage[i],maxn);	
	}
	if(maxn>=h){
		cout<<-1<<"\n";
		return 0;
	}
	int ans=0;
	ll cur = h;
	for(int i=0;i<n;i++){
		if(cur<=damage[i]) {
			ans++;
			cur = h;
		}
		cur-=damage[i];
	}
	cout<<ans<<"\n";
	return 0;
}
