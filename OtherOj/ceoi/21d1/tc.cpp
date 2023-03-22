#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int a;cin>>a>>a;
	}
	if(n<=2){
		cout<<"YES\n"<<n<<"\n";
		for(int i=0;i<n;i++) cout<<1<<" ";
		cout<<"\n";
		return 0;
	}
	cout<<"YES\n"<<2*(n-2)<<"\n";
	for(int i=2;i<=n-1;i++){
		cout<<i<<" ";
	}
	for(int i=n-1;i>=2;i--){
		cout<<i<<" ";
	}
	cout<<"\n";

	return 0;
}
