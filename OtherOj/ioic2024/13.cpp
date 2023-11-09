#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 1e6+5;
ll sum[N];
ll cnt[N];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,K;cin>>n>>K;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		if(!a) continue;
		sum[a]+=a;
		cnt[a]++;
	}
	for(int i=1;i<N;i++){
		sum[i]+=sum[i-1];
		cnt[i]+=cnt[i-1];
	}
	ll ans = 1e18;
	for(int k=K;k<N;k++){
		ll ret = 0;
		for(int i=0;i<N;i+=k){
			int l = i;
			int r = min(i+k-1,N-1);
			ret+=(sum[r]-sum[l])-(1LL*i*(cnt[r]-cnt[l]));
		}
		ans = min(ret,ans);
	}
	cout<<sum[N-1]-ans<<"\n";
	return 0;
}
