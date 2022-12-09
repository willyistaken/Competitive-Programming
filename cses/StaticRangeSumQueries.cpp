#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;	
	ll sum[n+1]={0};
	for(int i=1;i<=n;i++){
		cin>>sum[i];
		sum[i]+=sum[i-1];
	}
	while(q--){
		int a,b;cin>>a>>b;
		cout<<sum[b]-sum[a-1]<<"\n";
	}
	return 0;
}
