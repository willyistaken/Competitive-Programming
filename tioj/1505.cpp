#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int a;cin>>a;
		int mod; cin>>mod;
		a%=mod;
		for(int i=2;i<n;i++){
			int k;cin>>k;
			a = (1LL*a*k)%mod;
		}
		if(a){
			puts("zzz...");
		}else{
			puts("Asssss!!");	
		}
	}

	return 0;
}

// I only pass this by looking up the ans
/*
which is not good.
this is a really adhoc problem, I can't really find a solution
I don't know how I would learn to solve this...

*/
