#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct stone{
	int w;
	int p;
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int M;cin>>M;
	stone arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].w>>arr[i].p;
	}
	sort(arr,arr+n,[](const stone &a,const stone &b){return a.p>b.p;});
	ll sum=0;
	for(int i=0;i<n;i++){
		int wnow = min(M,arr[i].w);
		sum+=1LL*wnow*arr[i].p;
		M -= wnow;
		if(!M) break;
	}
	cout<<sum<<"\n";
	return 0;
}
