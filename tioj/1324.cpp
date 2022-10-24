#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<int> expo;
vector<int> cap;
const int N = 1e6+5;
int lowp[N];
vector<int> prime;

void init(){
	for(int i=2;i<N;i++){
		if(!lowp[i]){
			prime.push_back(i);
			lowp[i] = i;
		}
		for(int j = 0;j<prime.size() && i*prime[j]<N && lowp[i]>=prime[j];j++){
			lowp[i*prime[j]] = prime[j]; 
		}
	}
}

int pow(int a,int p,int mod){
	int r= 1;
	while(p){
		if(p&1) r = (mod>=0)?((1LL*r*a)%mod):(r*a);
		a = (mod>=0)?((1LL*a*a)%mod):(a*a);
		if(r<0 || a<0) return -1;
		p>>=1;
	}
	return r;
}

int phi(int k){
	int r = k;
	while(k>1){
		int p = lowp[k];	
		r = r/p;
		r*=(p-1);
		while(k%p==0) k/=p;
	}
	return r;
}
int n;
int calc(int l,int mod){
	if(l==n-1) return expo[l]%mod;
	if(__gcd(expo[l],mod)==1) return pow(expo[l],calc(l+1,phi(mod)),mod);
	int nmod = phi(mod);
	if(cap[l+1]>=nmod) return pow(expo[l],calc(l+1,nmod)+nmod,mod);
	else return pow(expo[l],cap[l+1],mod);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	init();
	while(cin>>n && n){
		expo.resize(n,0);
		cap.resize(n,0);
		fill(cap.begin(),cap.end(),0);
		for(int i=0;i<n;i++) cin>>expo[i];
		cap[n-1]=expo[n-1];
		for(int i=n-2;i>=0;i--){
			if(expo[i]<=1) cap[i] = expo[i];
			else{
				if(1LL*cap[i+1]*__lg(expo[i])>=31) cap[i] = 1e7;
				else{
					ll r = 1;
					for(int b=0;b<cap[i+1];b++){
						r = r*expo[i];
						if(r>1e6){
							r = 1e7;
							break;
						}
					}
					cap[i] = r;
				}

			}
		}
		int m;cin>>m;
		cout<<calc(0,m)<<"\n";
	}
	return 0;

}
