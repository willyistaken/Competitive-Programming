#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


void solve(){
	int n;cin>>n;
	int ans=  0;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		ans^=a;
	}
	if(n%2==0 && ans!=0){
		cout<<-1<<"\n";
		return ;
	}
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
