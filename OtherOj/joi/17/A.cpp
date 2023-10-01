#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q,s,t;cin>>n>>q>>s>>t;
	ll dif[n+1]={0};
	int a;cin>>a;
	ll sum = 0;
	for(int i=1;i<=n;i++){
		int b;cin>>b;	
		dif[i] = b-a;
		sum+=1LL*((dif[i]<0)?(t):(-s))*abs(dif[i]);
		a = b;
	}
	while(q--){
		int l,r,k;cin>>l>>r>>k;
		r++;
		sum-=1LL*((dif[l]<0)?(t):(-s))*abs(dif[l]);
		dif[l]+=k;
		sum+=1LL*((dif[l]<0)?(t):(-s))*abs(dif[l]);
		if(r<=n){
			sum-=1LL*((dif[r]<0)?(t):(-s))*abs(dif[r]);
			dif[r]-=k;
			sum+=1LL*((dif[r]<0)?(t):(-s))*abs(dif[r]);
		}
		cout<<sum<<"\n";
	}

	return 0;
}
