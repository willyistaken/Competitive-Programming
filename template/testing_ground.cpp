#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int mod = 20;
	for(int i=0;i<n;i++){
		cout<<i%mod<<" ";
	}
	cout<<"\n";
	for(int i =0 ;i<n;i++){
		cout<<2*i%mod<<" ";
	}
	cout<<"\n";

	return 0;
}
