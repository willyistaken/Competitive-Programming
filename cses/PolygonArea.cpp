#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


struct v{
	ll x;
	ll y;
};

ll operator^(const v &a,const v &b){
	return a.x*b.y-a.y*b.x;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	v arr[n];
	ll ans = 0;
	for(int i=0;i<n;i++){
		cin>>arr[i].x>>arr[i].y;
		if(i>0) ans+=(arr[i]^arr[i-1]);
	}
	ans+=arr[0]^arr[n-1];
	ans  = abs(ans);
	cout<<ans<<"\n";	
	return 0;
}
