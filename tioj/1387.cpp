#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int pp2(int _n){
	_n|=_n>>1;
	_n|=_n>>2;
	_n|=_n>>4;
	_n|=_n>>8;
	_n|=_n>>16;
	_n>>=1;
	return _n;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<int> w;
	vector<int> v;
	for(int i=0;i<n;i++){
		int wi,vi,ci;cin>>wi>>vi>>ci;
		int g = pp2(ci);
		w.push_back(wi*(ci-g));
		v.push_back(vi*(ci-g));
		while(g){	
			w.push_back((g & -g)*wi);
			v.push_back((g & -g)*vi);
			g-=(g & -g);
		}
	}
	n = w.size();
	int T;cin>>T;
	ll dp[T+1]={0};
	ll maxn=LONG_LONG_MIN;
	for(int i=0;i<n;i++){
		for(int j=T;j>=0;j--){
			if(w[i]<=j) dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
			maxn = max(dp[j],maxn);
		}
	}
	cout<<maxn<<"\n";	
	return 0;
}
