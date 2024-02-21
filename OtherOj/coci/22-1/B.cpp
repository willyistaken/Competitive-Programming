#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
//#include<bits/extc++.h>
//__gnu_pbds
// there is a windows of 0~2k and 2k~
// first choose the biggest 2k and above people, if 2k and above is too little let's say g, than calculate the  n-g furtherst to k and choose that;

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	vector<int> arr(n+1);
	for(int i=1;i<=n;i++) cin>>arr[i];
	sort(arr.begin()+1,arr.end());
	vector<ll> B(n+1);
	vector<ll> C(n+1);
	for(int i=1;i<=n;i++){
		B[i] = -arr[n-i+1];
		B[i]+=B[i-1];
	}
	for(int i=1;i<=n;i++){
		C[i] = arr[i];
		C[i]+=C[i-1];
	}
	int head = 1;
	vector<int> ans(q);
	vector<int> ord(q);
	vector<int> k(q);
	vector<int> m(q);
	for(int i=0;i<q;i++){
		ord[i]=i;
		cin>>k[i]>>m[i];
	}
	sort(ord.begin(),ord.end(),[&](const int &a,const int &b){return k[a]<k[b];});
	for(auto i : ord){
		while(head<=n && arr[head]<=k[i]){
			head++;
		}
		int l = -1;
		int r = min(head-1,m[i]);
		while(r-l>1){
			int M = (l+r)/2;
			ll v = C[M]+B[m[i]-M]+(2*k[i]*(m[i]-M));
			ll v2 = C[M+1]+B[m[i]-M-1]+(2*k[i]*(m[i]-M-1));
			if(v2<v) l = M;
			else r = M;
		}
		ans[i]= C[l+1]+B[m[i]-l-1]+(2*k[i]*(m[i]-l-1));
	}
	for(auto i : ans){
		cout<<i<<"\n";
	}
	return 0;
}
