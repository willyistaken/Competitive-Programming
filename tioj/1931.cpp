#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
#include <unistd.h>
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){
	int ans = 0; char c = RC(); bool minus = false;
	while((c < '0' or c > '9') and c != '-' and c != EOF) c = RC();
	if(c == '-') minus = true, c = RC();
	while(c >= '0' and c <= '9') ans = ans * 10 + (c ^ '0'), c = RC();
	return minus ? -ans : ans;
}
const int S = 1e6;
char outbuf[S]; int outp;
inline void W(ll n){
	static char buf[12], p;
	if(n == 0) outbuf[outp++] = '0';
	p = 0;
	if(n < 0){
		outbuf[outp++] = '-';
		while(n) buf[p++] = '0' - (n % 10), n /= 10;
	} else {
		while(n) buf[p++] = '0' + (n % 10), n /= 10;
	}
	for(--p; p >= 0; --p) outbuf[outp++] = buf[p];
	outbuf[outp++] = '\n';
	if(outp > S-12) fwrite(outbuf, 1, outp, stdout), outp = 0;
}


int main(){
	int t = R();
	while(t--){
		int n = R();
		int arr[n];
		for(int i=0;i<n;i++) arr[i] = R();
		sort(arr,arr+n);
		ll ans=0;
		for(int i=n-2;i>=0;i-=2){
			ans+=arr[i];	
		}
		W(4*ans);
	}
	fwrite(outbuf,1,outp,stdout);

	return 0;
}
