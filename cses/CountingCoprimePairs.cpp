#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int V = 1e6+5;
int cnt[V];
int u[V];
bool ntprime[V];
void init(){
	u[1]=1;
	for(int i=2;i<V;i++){
		if(!ntprime[i]) {
			u[i]=-1;
			for(int t = 2*i;t<V;t+=i){
				if(!ntprime[t]) u[t]=1;
				ntprime[t]=1;
				if((t/i)%i==0) u[t]=0;
				else u[t]*=-1;
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	init();
	for(int i=0;i<n;i++){
		int a;cin>>a;
		cnt[a]++;
	}
	ll ans = 0;
	for(int d=1;d<V;d++){
		if(u[d]==0) continue;
		ll sum = 0;
		for(int g = d;g<V;g+=d){
			sum+=cnt[g];
		}
		ans+=(sum*sum*u[d]);
		//if(sum!=0) cout<<d<<' '<<sum<<"\n";
	}
	ans-=cnt[1];
	cout<<(ans/2)<<"\n";
	return 0;
}
