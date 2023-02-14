#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int n;cin>>n;
	vector<pair<int,int>> odd,even;
	for(int i=0;i<n;i++){
		int a;cin>>a;	
		if(a&1) odd.push_back({a,i});
		else even.push_back({a,i});
	}
	if(odd.size()==0){
		cout<<"NO\n";
		return ;
	}
	if(n==3 && odd.size()==2){
		cout<<"NO\n";
		return ;
	}
	cout<<"YES"<<"\n";
	if(odd.size()>=3){
		cout<<odd[0].second+1<<" "<<odd[1].second+1<<" "<<odd[2].second+1<<"\n";
		return ;
	}
	cout<<odd[0].second+1<<' '<<even[0].second+1<<" "<<even[1].second+1<<"\n";	
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
