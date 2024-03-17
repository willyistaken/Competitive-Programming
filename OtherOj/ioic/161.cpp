#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 1e6+5;
int u[N];
int lp[N];
ll v[N];
vector<int> prime;
void init(){
	u[1]=1;
	v[1]=1;
	for(int i=2;i<N;i++){
		v[i]=i;
		if(lp[i]==0){
			lp[i]=i;
			prime.push_back(i);
			u[i]=-1;
		}
		for(auto p : prime){
			if(p>lp[i] || 1LL*i*p>=N) break;
			lp[i*p] = p;
			if(i%p==0) u[i*p]=0;
			else u[i*p] = u[i]*u[p];
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,k;cin>>n>>k;
	init();
	ll prev = 1;
	for(int i=1;i<=k;i++){
		ll ans = 0;
		for(int g=1;v[g]*g<=n;g++){
			v[g]*=g;
			ans+=u[g]*(n/v[g]);
		}
		cout<<ans-prev<<" ";
		prev = ans;
	}
	cout<<"\n";
	return 0;
}
