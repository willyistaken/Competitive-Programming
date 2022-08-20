#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

struct pt{
	ll x;
	ll y;
};

ll area(const pt &bl,const pt &tr){
	return (tr.x-bl.x)*(tr.y-bl.y);
}

struct range{
	int l;
	int r;
	int id;
};
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	pt arr[n];
	ll x=0;ll y=0;
	for(int i=0;i<n;i++){
		ll len;cin>>len;
		if(i%2) y-=len;
		else x+=len;
		arr[i]  = {x,y};
	}
	x=0;y=0;
	int m;cin>>m;
	pt arr2[m];
	for(int i=0;i<m;i++){
		ll len;cin>>len;
		if(i%2) x+=len;
		else y-=len;
		arr2[i] = {x,y};
	}
	deque<range> dp;
	dp.push_back({0,m,0});
	for(int i=1;i<n;i++){
		while(dp.size()){
			range temp = dp.back();
			if(area(arr2[temp.l],arr[temp.id])<=area(arr2[temp.l],arr[i])) dp.pop_back();
			else break;
		}
		if(dp.empty()){
			dp.push_back({0,m,i});	
		}else{
			range temp = dp.back();
			if(area(arr2[m-1],arr[temp.id])>area(arr2[m-1],arr[i]))	continue;
			int l = temp.l;
			int r = temp.r;
			while(r-l>1){
				int mid = (l+r)/2;
				if(area(arr2[mid],arr[temp.id])>area(arr2[mid],arr[i])) l=mid;
				else r = mid;
			}
			dp[dp.size()-1] = {temp.l,r,temp.id};
			dp.push_back({r,m,i});
		}
	}
	ll ans=0;
	for(int i=0;i<m;i++){
		while(dp.front().r<=i) dp.pop_front();
		ans = max(ans,area(arr2[i],arr[dp.front().id]));	
	}
	cout<<ans<<"\n";	



	return 0;
}
