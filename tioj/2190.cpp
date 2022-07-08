#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int MOD,a,b,xo,yo,xt,yt;

int ei(int x){
	int p = MOD-2;
	int ans=1;
	while(p){
		if(p & 1) ans = (1LL*ans*x)%MOD;
		x = (1LL*x*x)%MOD;
		p>>=1;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>MOD>>a>>b>>xo>>yo>>xt>>yt;	
		int inverse = ei(xt-xo);
		int m = (1LL*(yt-yo)*inverse)%MOD;
		int k = (1LL*yo-(1LL*m*xo))%MOD;
		int xh = (1LL*m*m-xo-xt)%MOD;
		xh = (xh<0)?xh+MOD:xh;
		int yh = (1LL*m*xh+1LL*k)%MOD;
		yh = (yh<0)?yh+MOD:yh;
		cout<<xh<<" "<<yh<<"\n";
	}
	return 0;
}


// m = (y2-y1)*(x2-x1)^-1;
// m^2 = x1+x2+x3
// y = mx+k
