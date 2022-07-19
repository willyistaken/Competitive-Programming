#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int b[1000];
int a[1000];
int m,k,n;

bool works(ll p){
	ll leftover=0;
	for(int i=0;i<n;i++){
		if(p*b[i]<a[i])	 return false;
		leftover += p*b[i]-a[i];
	}
	return (leftover>=(m*k));
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(cin>>n){
		for(int i=0;i<n;i++) cin>>b[i];	
		cin>>k;
		for(int i=0;i<n;i++) cin>>a[i];
		cin>>m;
		ll l=0;ll r= 1e5;
		while(r-l>1){
			ll mid = l+((r-l)/2);
			if(works(mid)) r = mid;
			else l = mid;
		}
		cout<<r<<"\n";
	}
	return 0;
}
