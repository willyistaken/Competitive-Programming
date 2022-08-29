#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	int t;scanf("%d",&t);
	while(t--){
		ll n,m,k;scanf("%lld%lld%lld",&n,&m,&k);
		puts((n&&m&&k)?(((n-1)^(m-1)^(k-1))?("First"):("Second")):("First"));	
	}

	return 0;
}
