#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

#include <unistd.h>
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){static char c;int a;while((c=RC())<'0');a=c^'0';while((c=RC())>='0')a*=10,a+=c^'0';return a;}


int main(){
	ll n;
	while(true){
		n = R();
		if(!n) return 0;
		if(n<3){
			puts("IMPOSSIBLE");
			continue;
		}
		int m=0;
		ll ans = ((n)*(n-1)*(n-2))/6;
		m = R();
		for(int i=0;i<m;i++){
			ll k = R();
			ans -= ((k)*(k-1)*(k-2))/6;
		}
		if(ans>0) printf("%lld\n",ans);
		else puts("IMPOSSIBLE");
		
	}

	return 0;
}
