#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
const int MOD = 1e9+7;

struct q{
	int l,r;
	short x;
};
int n;
short arr[1005];

int get(){
	int p[1005]={0};
	int u[1005]={0};
	int t[1005]={0};
	for(int i=1;i<=n;i++){
		p[i] = (p[i-1]+arr[i])%MOD;
		u[i] =( u[i-1]+((1LL*p[i]*p[i])%MOD))%MOD;
		t[i] = (t[i-1]+p[i])%MOD;
	}
	int ans=0;
	for(int l=1;l<=n;l++){
		ans+=(1LL*(n-l+1)*((1LL*p[l-1]*p[l-1])%MOD))%MOD;
		ans%=MOD;
		ans+=(u[n]-u[l-1])%MOD;
		ans%=MOD;
		ans-=(2LL*p[l-1]*(t[n]-t[l-1]))%MOD;
		ans%=MOD;
		if(ans<0) ans+=MOD;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	short og[n+1];
	for(int i=1;i<=n;i++){
		cin>>og[i];
		arr[i] =og[i];
	}
	int Q;
	cin>>Q;
	q qu[Q];
	for(int i=0;i<Q;i++){
		cin>>qu[i].l>>qu[i].r>>qu[i].x;	
	}
	int ans=0;
	for(int s=0;s<(1<<Q);s++){
		for(int i=0;i<Q;i++){
			if((s>>i)&1){
				for(int r = qu[i].l;r<=qu[i].r;r++){
					arr[r]^=qu[i].x;
				}
			}
		}
		ans+=get();
		ans%=MOD;
		for(int i=1;i<=n;i++) arr[i] = og[i];
	}
	cout<<ans<<"\n";
	return 0;
}
