#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int MOD = 998244353;
const int M = 998244352;
const int N = 1e5+5;
ll sum[N];
ll sum2[N];
ll cnt[N];
int u[N];
int pft[N];
vector<int> prime;

ll pw(int a,int p){
	ll r = 1;
	if(p<0) return 1;
	while(p){
		if(p&1)	r = (r*a)%MOD;
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}

void init(){
	pft[1]=1;
	for(int i=1;i<N;i++) u[i]=1;
	for(int i=2;i<N;i++){
		if(pft[i]==0){
			prime.push_back(i);
			for(int j=i;j<N;j+=i){
				pft[j]=i;
				u[j]*=-1;
				if((j/i)%i==0) u[j]=0;
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	init();
	vector<int> a(n);
	vector<int> b(n);
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		vector<int> plist;
		int v = a[i];
		while(v!=1){
			int p = pft[v];
			plist.push_back(p);
			while(v%p==0) v/=p;
		}
		int c = plist.size();
		for(int mask=0;mask<(1<<c);mask++){
			int rep = 1;	
			for(int j=0;j<c;j++){
				if((mask>>j)&1){
					rep*=plist[j];
				}
			}
			cnt[rep]=(cnt[rep]+b[i])%M;
			sum[rep]=(sum[rep]+1LL*b[i]*a[i])%MOD;
			sum2[rep] = (sum2[rep]+1LL*((1LL*b[i]*a[i])%MOD)*a[i])%MOD;
		}
	}
	for(int i=1;i<N;i++){
		//if(u[i]==0) continue;
		cnt[i]+=M;
		ll IIxySUM = (((sum[i]*sum[i])%MOD)-((sum2[i])%MOD))%MOD;
		if(IIxySUM<0) IIxySUM+=MOD;
		sum[i] = (pw(2,cnt[i]-1)*sum[i])%MOD;
		sum2[i] = ((sum2[i]*pw(2,cnt[i]-1))%MOD+(IIxySUM*pw(2,cnt[i]-2))%MOD)%MOD;
	//	if(i<10) cout<<cnt[i]%M<<" "<<sum[i]<<" "<<sum2[i]<<"\n";
	}
	ll total = 0;
	ll total2 = 0;
	for(int i=1;i<N;i++){
		total = (total+u[i]*sum[i])%MOD;
		total2 = (total2+u[i]*sum2[i])%MOD;
	}
	//cout<<total<<" "<<total2<<"total\n";
	sum[1]-=total;
	sum2[1]-=total2;
	ll ans = 0;
	for(int i=0;i<n;i++){
		vector<int> plist;
		int v = a[i];
		while(v!=1){
			int p = pft[v];
			plist.push_back(p);
			while(v%p==0) v/=p;
		}
		int c = plist.size();
		ll isum=0;
		ll isum2=0;
		
		for(int mask = 0;mask<(1<<c);mask++){
			ll rep = 1;	
			int mop = 1;
			for(int j=0;j<c;j++){
				if((mask>>j)&1){rep*=plist[j];mop*=-1;}
			}
			isum = (isum+mop*sum[rep])%MOD;
			isum2 = (isum2+mop*sum2[rep])%MOD;
		}
	//	cout<<isum<<" "<<isum2<<"\n";
		ans=(ans+(b[i]*((isum2+(a[i]*isum))%MOD))%MOD)%MOD;
	}
	if(ans<0) ans+=MOD;
	cout<<ans<<"\n";
	return 0;
}
