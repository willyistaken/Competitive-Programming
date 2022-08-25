#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

int ans(int n){
	if(n==1) return 1;
	if(n%2==0){
		return ((n<=2)?(0):(n/2));
	}
	return ans(n/2);
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int k,n;cin>>k>>n;
	if(k==1){
		cout<<n<<"\n";
		return 0;
	}else{
		cout<<ans(n)<<"\n";
	}

	return 0;
}
