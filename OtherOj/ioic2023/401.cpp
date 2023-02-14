#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	if(n==3){
		cout<<"0 1\n-1 0\n";
		return 0;
	}
	cout<<"0.839286755214161 0.543689012692077\n-0.839286755214161 0.543689012692077\n-1 0\n";
	n-=4;
	ll s = 100000000000000;		
	for(int i=1;i<=n;i++){
		cout<<"-0."<<s-i<<" "<<0<<'\n';
	}

	return 0;
}
