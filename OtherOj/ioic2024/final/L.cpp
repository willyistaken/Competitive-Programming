#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


const int N =1e6+5;
const int A = 2e6+5;
const int MOD = 998244353;
int mulcnt[A];
int cnt[A];
int u[A];
int d[A];
int ans[N];
vector<int> prime;
int fac[A];
int invfac[A];
int pow(int a,int p){
	ll r = 1;
	while(p){
		if(p&1) r = (r*a)%MOD;
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}

int c(int n,int k){
	if(k>n) return 0;
	ll r = fac[n];
	r = (1LL*r*invfac[n-k])%MOD;
	r = (1LL*r*invfac[k])%MOD;
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;	
	u[1]=1;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		mulcnt[a]++;
	}
	for(int i=2;i<A;i++){
		if(!d[i]){
			prime.push_back(i);
			d[i]=i;
			u[i]=-1;
		}
		for(int p:prime){
			if(i*p>=A) break;
			d[i*p]=p;
			u[i*p] = u[i]*u[p];
			if(i%p==0){
				u[i*p]=0;
				break;
			}
		}
	}
	fac[0]=1;
	for(int i=1;i<A;i++){
		fac[i]	 = (1LL*fac[i-1]*i)%MOD;
	}
	invfac[A-1]=pow(fac[A-1],MOD-2);
	for(int i=A-2;i>=0;i--)	{
		invfac[i]= (1LL*invfac[i+1]*(i+1))%MOD;
	}

	for(int i=1;i<A;i++){
		for(int j=i;j<A;j+=i){
			cnt[i]+=mulcnt[j];
		}
	}
	for(int i=1;i<A;i++){
		for(int j=1;j<=cnt[i];j++)	{
			ans[j] = (ans[j]+u[i]*c(cnt[i],j))%MOD;
		}
	}
	for(int i=1;i<=n;i++){
		if(ans[i]<0) ans[i]+=MOD;
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
}

