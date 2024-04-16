#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")

namespace {
  // 如果你有任何全域變數可以在這邊宣告。請注意：正式評分程式會呼叫你實作的 count() 函式 T <= 5 次。
  
  // 如果你覺得有需要在所有 count() 開始之前做點什麼，可以利用以下這個變數和 initialize() 函數。
  const int S = 3e7+5;
  int p[S];
  bool initialized = false;
  void initialize() {
  	initialized=1;
	std::vector<int> prime;
  	for(int i=2;i<S;i++)	{
		if(!p[i]){
			p[i]=i;
			prime.push_back(i);
		}
		for(auto v : prime){
			if(v>p[i]) break;
			if(v*i>=S) break;
			p[v*i]=v;
		}
	}
    return;
  }
}
using namespace std;
typedef long long ll;
int po(int a,int p,int mod){
	ll r = 1;
	while(p){
		if(p&1) r = (1LL*r*a)%mod;
		a = (1LL*a*a)%mod;
		p>>=1;
	}
	return r;
}
std::vector<int> count(const std::vector<int> &a) {
  if (!initialized) initialize();
  	vector<int> C(S,0);
  	int n = a.size();
	int B = 25;
	vector<int> sum(n+1);
	for(int i=1;i<=n;i++){
		sum[i] =sum[i-1]+a[i-1];
	}
	vector<int> result;
	for(int j=3;j<=n;j++){
		int t = 0;
		int ans = 0;	
		for(int i=j-2;i>=max(j-B,1);i--){
			int a = sum[i];
			int b = sum[j-1]-a;
			int c = sum[n]-a-b;
			t=c;
			if(po(a,b,c)==0) ans++;
		}
		int c = (j-B-1);

		if(c>=1){
			int v = sum[c];
			vector<int> primef;	
			while(v>1){
				if(!p[v]) p[v]=v;
				primef.push_back(p[v]);
				v/=p[v];
			}
			sort(primef.begin(),primef.end());
			primef.resize(unique(primef.begin(),primef.end())-primef.begin());
			int m = primef.size();
			for(int k=0;k<(1<<m);k++)	{
				int ff = 1;
				for(int i=0;i<m;i++) if((k>>i)&1) ff*=primef[i];
				C[ff]++;
			}
		}

		int f = 1;
		while(t>1){
			if(!p[t]) p[t]=t;
			f*=p[t];
			int P = p[t];
			while(t%P==0){
				t/=P;
			}
		};
		ans+=C[f];
		result.push_back(ans);
	}
	return result;
}
