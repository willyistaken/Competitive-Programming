#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int cnt[n]={0};
	ll sum[n+1]={0};
	ll ans = 0;
	cnt[0]=1;
	for(int i=1;i<=n;i++){
		cin>>sum[i];
		sum[i]+=sum[i-1];
		sum[i]%=n;
		if(sum[i]<0) sum[i]+=n;
		ans+=cnt[sum[i]];
		cnt[sum[i]]++;
	}
	cout<<ans<<"\n";


	return 0;
}
