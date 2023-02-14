#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct s{
	map<int,int> mp;
	int m;
	void add(int x){
		if(x>m) return;	
		mp[x]++;
	}
	void remove(int x){
		if(x>m) return ;
		mp[x]--;
		if(mp[x]==0) mp.erase(x);
	}
	void addn(int n){
		ll j=1;
		for(;j*j<n&&j<=m;j++){
			if(n%j==0){
				add(j);	
				add(n/j);
			}
		}
		if(j*j==n){
			add(j);
		}
	}

	void removen(int n){
		ll j=1;
		for(;j*j<n&&j<=m;j++){
			if(n%j==0){
				remove(j);	
				remove(n/j);
			}
		}
		if(j*j==n){
			remove(j);
		}
	}
};

void solve(){
	int n,m;cin>>n>>m;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	s check;
	check.m = m;
	int po = 0;
	int ans = 1e9+5;
	for(int i=0;i<n;i++){
		check.addn(arr[i]);
		if(check.mp.size()!=m) continue;
		while(check.mp.size()==m && po<i) check.removen(arr[po++]); 
		if(po==i && check.mp.size()==m){
			cout<<0<<"\n";
			return;
		}
		ans = min(ans,arr[i]-arr[po-1]);
	}
	if(ans>1e6) cout<<-1<<"\n";
	else{
		cout<<ans<<"\n";
	}
	
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
