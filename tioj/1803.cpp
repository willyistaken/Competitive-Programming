#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6+5;
const int MOD = 1e9+7;

int fac[MAXN];

void init(){
	fac[0]=1;
	fac[1]=1;	
	for(int i=2;i<MAXN;i++){
		fac[i] = (1LL*fac[i-1]*i)%MOD;
	}
		
}
int power(int a,int p){
	int r=1;
	while(p){
		if(p&1) r = (1LL*r*a)%MOD;
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}

int solve(int n,int k){
	if(n%k) return 0;
	int looppart = fac[k-1];
	looppart = power(looppart,n/k);
	int numer= fac[n];
	int	denom = (1LL*fac[n/k] * power(fac[k],n/k))%MOD;
	int invdenom = power(denom,MOD-2);
	int grouppart = (1LL*numer*invdenom)%MOD;
	return (1LL*looppart*grouppart)%MOD;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	init();		
	int n,k;
	while(cin>>n>>k){
		if(k==1){
			cout<<0<<"\n";
			continue;
		}
		ll ans=0;
		for(int i=2;i<=k;i++){
			if(k%i==0){
				ans+=solve(n,i);	
				ans%=MOD;
			}
		}
		cout<<ans<<"\n";
	}

	return 0;
}

// the same the way to 1. partition n stuff in to n/k loop, 2. find the differnce permutation of a size n/k loop
/*
AHA. by simple mutiplie principle, a loop of size g have (g-1)! permutations;
STUCK: now what?
AHA. 
1. Way of distributing n item in k bucket:
      n!/((n/k)!*(k!)^n/k))
by using the law of multiplicity 

2. Way of permutation in a size n loop:
   It is (n-1)! 

need to consider all case that fit the def


*/
