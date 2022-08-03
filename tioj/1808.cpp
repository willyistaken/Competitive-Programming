#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n=9;
	int mod=10;
	for(int i=1;i<=n;i++){
		for(int i=mod/10;i<mod;i++){
			if((1LL*i*i)%mod==i) cout<<i<<"\n";		
		}
		mod*=10;
	}

	return 0;
}

/*stuck no pattern detected*/
