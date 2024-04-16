#include<bits/stdc++.h>


namespace {
  // 如果你有任何全域變數可以在這邊宣告。請注意：正式評分程式會呼叫你實作的 count() 函式 T <= 5 次。
  
  // 如果你覺得有需要在所有 count() 開始之前做點什麼，可以利用以下這個變數和 initialize() 函數。
  bool initialized = false;
  void initialize() {
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
  	int n = a.size();
	vector<int> sum(n+1);
	for(int i=1;i<=n;i++){
		sum[i] = sum[i-1]+a[i-1];
	}
	vector<int> result;
	for(int j=2;j<n;j++){
		int ans = 0;	
		for(int i=j-1;i>=1;i--){
			int a = sum[i];
			int b = sum[j]-a;
			int c = sum[n]-a-b;
			if(po(a,b,c)==0) ans++;
		}
		result.push_back(ans);
	}
	return result;
	


}
