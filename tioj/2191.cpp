#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct pt{
	int x=0;
	int y=1;
	int w=0;
};

bool comp(pt &a,pt &b){
	pt n = a;
	pt m = b;
	if(n.x<0) n.x=-n.x,n.y=-n.y;
	if(m.x<0) m.x=-m.x,m.y=-m.y;
	return (1LL*n.x*m.y<1LL*n.y*m.x);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<pt> arr(n);
	for(int i=0;i<n;i++) {
		cin>>arr[i].x>>arr[i].y>>arr[i].w;
		if(arr[i].x==0) arr[i].y = abs(arr[i].y);
	}
	//note to self: stl sort's compare function must be "stricly weak ordering" meaning that comp(x,x) must always be false , otherwise you will get MLE
	sort(arr.begin(),arr.end(),comp);
	

	vector<ll> cirmaxarr;
	for(int i=0;i<n;i++){
		ll sumpt=0;
		pt now=arr[i];
		while(i<n && 1LL*arr[i].x*now.y-1LL*arr[i].y*now.x==0){
			sumpt+=arr[i].w;
			i++;
		}
		cirmaxarr.push_back(sumpt);
		i--;
	}
	ll maxcir=0;
	ll sum=0;
	ll allsum=0;
	for(auto i : cirmaxarr){
		if(sum<0) sum=i;
		else sum+=i;
		allsum+=i;
		maxcir = max(sum,maxcir);
	}
	ll mincir=1e14;
	sum=0;
	for(auto i : cirmaxarr){
		if(sum>0) sum=i;
		else sum+=i;
		mincir = min(sum,mincir);
	}
	cout<<max(maxcir,allsum-mincir)<<"\n";
	return 0;
}
