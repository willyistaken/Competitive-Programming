#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		ll ans=0;	
		int flag=0;
		for(int i=0;i<n-1;i++){
			int k;cin>>k;
			ans+=max(k,flag);
			if(k) flag=1;
		}
		int g;cin>>g;
		cout<<ans<<"\n";
	}
	return 0;
}
