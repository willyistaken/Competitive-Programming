#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

struct pt{
	int x;
	int y;
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	pt arr[n];
	ll ans=0;
	for(int i=0;i<n;i++) cin>>arr[i].x>>arr[i].y;
	sort(arr,arr+n,[](const pt &a,const pt &b){return (a.x==b.x)?(a.y<b.y):(a.x<b.x);});
	for(int i=0;i<n-1;i++){
		if(arr[i].x==arr[i+1].x) ans++;
	}
	sort(arr,arr+n,[](const pt &a,const pt &b){return (a.y==b.y)?(a.x<b.x):(a.y<b.y);});
	for(int i=0;i<n-1;i++){
		if(arr[i].y==arr[i+1].y) ans++;
	}
	sort(arr,arr+n,[](const pt &a,const pt &b){return (a.x+a.y==b.x+b.y)?(a.y>b.y):(a.x+a.y<b.x+b.y);});
	for(int i=0;i<n-1;i++){
		if(arr[i].x+arr[i].y==arr[i+1].x+arr[i+1].y) ans++;
	}

	sort(arr,arr+n,[](const pt &a,const pt &b){return (a.x-a.y==b.x-b.y)?(a.y>b.y):(a.x-a.y<b.x-b.y);});
	for(int i=0;i<n-1;i++){
		if(arr[i].x-arr[i].y==arr[i+1].x-arr[i+1].y) ans++;
	}
	cout<<ans<<"\n";



}
