#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct pt{
	ll x;
	ll y;
};

pt operator-(const pt a,const pt b){
	pt r = {a.x-b.x,a.y-b.y};
	return r;
}

ll operator^(const pt a,const pt b){
	ll k = a.x*b.y-a.y*b.x;
	return k;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll ans = 0;
	int n;cin>>n;							
	pt arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].x>>arr[i].y;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			pt v = arr[j]-arr[i];
			ll l = 0;ll r = 0;
			for(int k = 0;k<n;k++){
				pt u = arr[k]-arr[i];
				if((v^u)>0) r++;
				else if((v^u)<0)l++;
			}
			ans+=l*r;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
