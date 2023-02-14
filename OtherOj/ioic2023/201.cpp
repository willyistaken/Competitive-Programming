#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	if(n>30){
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
	for(int i=0;i<n;i++){
		cout<<((1<<30)-1)-(1<<i)<<" ";
	}
	cout<<"\n";

	return 0;
}
