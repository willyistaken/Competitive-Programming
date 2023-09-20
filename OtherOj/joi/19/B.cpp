#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


struct painting{
	int v;
	int s;
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	vector<painting> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i].s>>arr[i].v;
	sort(arr.begin(),arr.end(),[&](const painting &a,const painting &b){return (a.v==b.v)?(a.s<b.s):(a.v<b.v);});
	vector<int> frame(m);
	for(int i=0;i<m;i++) cin>>frame[i];
	sort(frame.begin(),frame.end());
	int ans = 0;
	for(int i=n-1;i>=0;i--){
		if(ans>=m) break;
		if(frame[m-ans-1]>=arr[i].s) ans++;
	}
	cout<<ans<<"\n";
	


	return 0;
}
