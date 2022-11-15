#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct stuff{
	int l;
	int r;
	int id;
	bool ans;
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	stuff arr[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i].l>>arr[i].r;
		arr[i].id = i;
	}
	sort(arr,arr+n,[](const stuff &a,const stuff &b){return (a.r==b.r)?(a.l>b.l):(a.r<b.r);});
	int maxn = -1;
	for(int i=0;i<n;i++){
		arr[i].ans = maxn>=arr[i].l;
		maxn = max(maxn,arr[i].l);
	}
	sort(arr,arr+n,[](const stuff &a,const stuff &b){return a.id<b.id;});
	for(int i=0;i<n;i++) cout<<arr[i].ans<<" \n"[i==n-1];
	sort(arr,arr+n,[](const stuff &a,const stuff &b){return (a.r==b.r)?(a.l<b.l):(a.r>b.r);});
	int minn = 1e9;
	for(int i=0;i<n;i++){
		arr[i].ans = minn<=arr[i].l;
		minn = min(minn,arr[i].l);
	}
	sort(arr,arr+n,[](const stuff &a,const stuff &b){return a.id<b.id;});
	for(int i=0;i<n;i++) cout<<arr[i].ans<<" \n"[i==n-1];
	return 0;
}
