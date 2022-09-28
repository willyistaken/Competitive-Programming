#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

//joseph problem


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	k--;
	for(int m=2;m<=30000;m++){
		int f=0;
		for(int i=2;i<=n;i++){
			f = (f+m)%i;
		}
		if(f==k){
			cout<<m<<"\n";
			return 0;
		}
	}
	cout<<0<<"\n";

	return 0;
}
