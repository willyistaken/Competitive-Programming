#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

//if(k<=n/2) return 2*k-1; return 2*f(n/2,k-n/2);

int f(int n,int k){
	if(n==1) return 1;
	if(k<=(n+1)/2){
		if(2*k>n) return (2*k)%n;
		else return 2*k;
	}
	int b = f(n/2,k-(n+1)/2);
	if(n&1) return 2*b+1;
	else return 2*b-1;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int q;cin>>q;	
	while(q--){
		int n,k;cin>>n>>k;
		cout<<f(n,k)<<"\n";
	}

	return 0;
}
