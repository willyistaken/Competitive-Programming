#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define int ll
ll n,m;
vector<int> a;
vector<int> b;
bool check(ll k){
	ll left = 0;							
	for(int i=0;i<n;i++){
		ll c = k;
		ll g = (c/a[i])+((c%a[i])!=0);
		if(g>m)	{
			c-=(m*a[i]);
			left -= ((c/b[i])+((c%b[i])!=0));
		}else{
			left+=m-g;			
		}
	}
	return left>=0;
}


signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;		
	a.resize(n);b.resize(n);
	for(int i=0;i<n;i++) cin>>a[i];
	ll maxnn = 0;
	for(int i=0;i<n;i++) {
		cin>>b[i];
		a[i] = max(a[i],b[i]);
		maxnn  = max(maxnn,a[i]);
	}
	long long l = 0; long long r = 1e18+2;
	while(r-l>1){
	 	long long mid = l+((r-l)/2);
		if(check(mid)){
			l = mid;
		}else{
			r = mid;	
		}
	}
	cout<<l<<"\n";
	return 0;
}
