#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds



map<int,int> mp;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;	
	int q;cin>>q;
	if(q!=1) {
		cout<<0<<"\n";
		return 0;
	}
	for(int i=0;i<n;i++){
		int a;cin>>a;
		mp[a]++;
	}
	cin>>q>>q;
	vector<int> stuff;
	for(auto i : mp){
		stuff.push_back(i.second);
	}
	sort(stuff.begin(),stuff.end());
	vector<int> ordering(stuff.size());
	int m = stuff.size();
	for(int i=0;i<m/2;i++){
		ordering[i] = stuff[2*i];
		ordering[m-i-1] =stuff[2*i+1];
	}
	if(m%2) ordering[(m/2)] =stuff.back();
	ll ans = 0;
	ll sum = 0;
	for(int i=0;i<m;i++){
		sum+=ordering[i];
		ans+=sum*(n-sum);
	}
	ans+=(1LL*n*n+n)/2;
	cout<<ans<<"\n";
	return 0;
}
