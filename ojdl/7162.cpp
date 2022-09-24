#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
int n;
vector<int> arr;
vector<ll> sarr;


ll sum(int l,int r){
	return sarr[r]-sarr[l];
}

ll ans(int l,int r){
	if(r-l<1) return 0;
	if(r-l==1) return 1;
	int mid = (l+r)/2;
	ll others = ans(l,mid)+ans(mid,r);
	int lmax[mid-l+1]={0};
	int rmax[r-mid+1]={0};
	for(int i=1;i<=mid-l;i++) lmax[i] = max(lmax[i-1],arr[mid-i]);
	for(int i=1;i<=r-mid;i++) rmax[i] = max(rmax[i-1],arr[mid+i-1]);

	ll ans=0;
	// assume left max(>=);

	for(int i=1;i<=mid-l;i++){
			ll suml = sum(mid-i,mid);
			int lb=0;int rb = r-mid+1;
			while(rb-lb>1){
				int m = (lb+rb)/2;
				if(rmax[m]<=lmax[i]) lb=m;
				else rb = m;	
			}
			int sl = 0;int sr = rb;
			while(sr-sl>1){
				int m = (sr+sl)/2;
				if(suml+sum(mid,mid+m)<=(1LL*lmax[i]*lmax[i]))	sl=m;
				else sr = m;
			}
			ans+=sl;
	}


	// assume right max(>);


	for(int i=1;i<=r-mid;i++){
			ll sumr = sum(mid,mid+i);
			int lb=0;int rb = mid-l+1;
			while(rb-lb>1){
				int m = (lb+rb)/2;
				if(lmax[m]<rmax[i]) lb=m;
				else rb = m;	
			}
			int sl = 0;int sr = rb;
			while(sr-sl>1){
				int m = (sr+sl)/2;
				if(sumr+sum(mid-m,mid)<=(1LL*rmax[i]*rmax[i]))	sl=m;
				else sr = m;
			}
			ans+=sl;
	}
	//cout<<l<<" "<<mid<<" "<<r<<" : "<<ans<<"\n";	
	return ans+others;		


}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	arr.resize(n);
	sarr.resize(n+1,0);
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=1;i<=n;i++) sarr[i] = sarr[i-1]+arr[i-1];
	cout<<ans(0,n)<<"\n";
	return 0;
}
