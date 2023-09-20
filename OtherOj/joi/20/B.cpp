#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	vector<int> J(n+1,0);
	vector<int> O(n+1,0);
	vector<int> I(n+1,0);
	string s;cin>>s;	
	for(int i=1;i<=n;i++){
		J[i]=J[i-1];
		O[i]=O[i-1];
		I[i]=I[i-1];
		if(s[i-1]=='J') J[i]++;
		if(s[i-1]=='O') O[i]++;
		if(s[i-1]=='I') I[i]++;
	}
	int ans = 1e9;
	for(int i=1;i<=n;i++){
		if(s[i-1]!='I') continue;
		int l = -1;int r = i;
		int t = i;
		while(r-l>1){
			int mid = (l+r)/2;
			if(I[t]-I[mid]>=k) l = mid;
			else r = mid;
		}
		r = l;l = -1;
		if(r<=0) continue;
		t = r;
		while(r-l>1){
			int mid = (l+r)/2;
			if(O[t]-O[mid]>=k) l = mid;
			else r = mid;
		}
		r = l;l = -1;
		if(r<=0) continue;
		t = r;
		while(r-l>1){
			int mid = (l+r)/2;
			if(J[t]-J[mid]>=k) l=mid;
			else r = mid;
		}
		if(l>=0){
			ans = min(ans,i-l-3*k);
		}
	}
	if(ans>=1e7) cout<<-1<<"\n";
	else cout<<ans<<"\n";

	return 0;
}
