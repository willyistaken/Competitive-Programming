#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int MOD = 1e6+3;

struct dsu{
	vector<int> arr;
	int n;
	void init(int _n){
		 n = _n;	
		 arr.resize(n);
		 for(int i=0;i<n;i++) arr[i]=i;
	}
	int query(int a){
		if(arr[a]==a) return a;
		arr[a] = query(arr[a]);
		return arr[a];
	}
	void join(int a,int b){
		a = query(a);
		b = query(b);
		if(a!=b) arr[a]=b;
	}
};

vector<int> fac;
vector<int> invfac;

int C(int n,int k){
	ll r = 1LL*((1LL*fac[n]*invfac[k])%MOD)*invfac[n-k]%MOD;
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;	
	fac.resize(k+1);
	invfac.resize(k+1);
	fac[0]=1;
	for(int i=1;i<=k;i++) fac[i] = (1LL*fac[i-1]*i)%MOD;
	ll g = fac[k];
	ll r = 1;
	ll p = MOD-2;
	while(p){
		if(p&1) r = (r*g)%MOD;
		g = (g*g)%MOD;
		p>>=1;
	}
	invfac[k]=r;
	for(int i=k;i>=1;i--){
		invfac[i-1] = (1LL*invfac[i]*i)%MOD;
	}
	vector<int> arr(n-k+1);
	for(int i=0;i<n-k+1;i++){
		cin>>arr[i];
	}
	dsu d;
	d.init(n);
	vector<int> hasto(n,-1);
	for(int i=0;i<n-k;i++){
		if(arr[i]==arr[i+1]){
			d.join(i,i+k);
		}else if(arr[i]+1==arr[i+1]){
			hasto[i]=0;
			hasto[i+k]=1;
		}else{
			hasto[i]=1;
			hasto[i+k]=0;
		}
	}
	for(int i=0;i<n;i++)	{
		int a = d.query(i);
		if(hasto[i]!=-1) hasto[a]=hasto[i];
	}
	for(int i=0;i<n;i++)	{
		hasto[i] = hasto[d.query(i)];
	}
	map<int,int> stuff;
	int cnt = 0;
	int cnt2 = 0;
	for(int i=0;i<k;i++){
		if(hasto[i]==1) cnt++;
		if(hasto[i]==-1){
			cnt2++;
		}
	}
	int K = arr[0]-cnt;
	cout<<C(cnt2,K)<<"\n";
	return 0;
}
