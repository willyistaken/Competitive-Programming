#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int MOD = 1e9+7;
const int N = 1e5+5;
int p2[N];

inline int mul(const int &a,const int &b){
	return (1LL*a*b)%MOD;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	p2[0]=1;
	int q;cin>>q;
	for(int i=1;i<=max(q,100);i++) p2[i] = (2LL*p2[i-1])%MOD;
	vector<tuple<int,int,int> > Q(q);
	for(int i=0;i<q;i++){
		cin>>get<0>(Q[i])>>get<1>(Q[i])>>get<2>(Q[i]);
	}
	ll ans = 0;
	for(int b1=0;b1<7;b1++){for(int b2=0;b2<7;b2++){
		vector<int> cnt1(n+2,0);
		vector<int> cnt2(n+2,0);
		vector<vector<int> > both(n+2,vector<int>(n+2,0));
		for(auto &[l,r,x] : Q){
			if((x>>b1)&1) cnt1[l]++,cnt1[r+1]--;
			if((x>>b2)&1) cnt2[l]++,cnt2[r+1]--;
			if(((x>>b1)&1) & ((x>>b2)&1)){
				both[l][l]++;both[l][r+1]--;
				both[r+1][l]--;both[r+1][r+1]++;
			}
		}
		for(int i=1;i<=n;i++){
			cnt1[i]+=cnt1[i-1];
			cnt2[i]+=cnt2[i-1];
			for(int j=1;j<=n;j++) both[i][j]+=both[i][j-1];
			for(int j=1;j<=n;j++) both[i][j]+=both[i-1][j];
		}
		for(int l=1;l<=n;l++){
			for(int r=1;r<=n;r++){
				int bO = (both[l][r]==0)?(0):(p2[both[l][r]]);
				int bE =  p2[both[l][r]];
				int o1 = (cnt1[l]-both[l][r]==0)?(0):(p2[cnt1[l]-both[l][r]]);
				int e1 =  p2[cnt1[l]-both[l][r]];
				int o2 = (cnt2[r]-both[l][r]==0)?(0):(p2[cnt2[r]-both[l][r]]);
				int e2 =  p2[cnt2[r]-both[l][r]];
				if((a[l]>>b1)&1) swap(o1,e1);
				if((a[r]>>b2)&1) swap(o2,e2);
				cout<<bO<<" "<<bE<<" "<<o1<<" "<<e1<<" "<<o2<<" "<<e2<<"\n";
				ll v = (mul(bO,mul(e1,e2))+mul(bE,mul(o1,o2)))%MOD;
				v = (v*p2[q-cnt1[l]-cnt2[r]+both[l][r]])%MOD;
				v = mul(v,mul(min(l,r),(n-max(l,r)+1)));
				v = mul(v,p2[b1+b2]);
				ans = (ans+v)%MOD;
			}
		}
	}}
	cout<<ans<<"\n";
	return 0;
}
