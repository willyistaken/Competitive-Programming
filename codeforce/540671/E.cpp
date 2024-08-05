#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define int ll
int k;

int dis(int a,int b){
	return min(abs(a-b),k-abs(a-b));
}

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;cin>>k>>n;
	k*=2;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
		arr[i]--;
		arr[i]*=2;
	}
	vector<int> ind(n,0);
	set<pair<int,int> > s;
	for(int i=0;i<n;i++){
		int b = (arr[i]+(k/2))%k;
		int r = upper_bound(arr.begin(),arr.end(),b)-arr.begin();
		int l = r-1;
		r = (r+n)%n;
		l = (l+n)%n;
		if(dis(arr[r],arr[i])>=dis(arr[l],arr[i])) {s.insert({min(i,r),max(i,r)});}
		if(dis(arr[r],arr[i])<=dis(arr[l],arr[i])) {s.insert({min(i,l),max(i,l)});}
	}
	for(auto i : s){
		ind[i.first]++;
		ind[i.second]++;
	}

	int ans = 0;
	for(int i=0;i<n;i++) ans = max(ans,ind[i]);
	for(int i=0;i<n;i++){
		int b = (arr[i]+k/2)%k;
		int r = upper_bound(arr.begin(),arr.end(),b)-arr.begin();
		int l = r-1;
		r = (r+n)%n;
		l = (l+n)%n;
		if(dis(arr[r],arr[i])==dis(arr[l],arr[i])){
			if(s.count({l,r}) || s.count({r,l})) ans = max(ans,3LL);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
