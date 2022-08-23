#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
#include <unistd.h>
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){
	int ans = 0; char c = RC(); bool minus = false;
	while((c < '0' or c > '9') and c != '-' and c != EOF) c = RC();
	if(c == '-') minus = true, c = RC();
	while(c >= '0' and c <= '9') ans = ans * 10 + (c ^ '0'), c = RC();
	return minus ? -ans : ans;
}
const int S = 60000;
char outbuf[S]; int outp;
inline void W(int n){
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
int n;
struct bit{
	vector<int> arr;
	int size;
	void init(){
		arr.resize(n+2);
		size = n+1;
	}

	void add(int ind,int v){
		ind++;
		while(ind<=size){
			arr[ind] = max(arr[ind],v);
			ind+=(ind & -ind);
		}
	}

	int query(int ind){
		ind++;
		int r=0;
		while(ind){
			r = max(arr[ind],r);
			ind-= (ind & -ind);
		}
		return r;
	}
};



int main(){
	int t; t  = R();
	//cin>>t;
	while(t--){
		n = R();
		//cin>>n;
		vector<ll> arr(n+1,0);
		for(int i=1;i<=n;i++){
			arr[i] = R();
			//cin>>arr[i];
			arr[i]+=arr[i-1];
		}
		vector<pair<int,int> > fromrsafe(n+1,make_pair(0,0));
		stack<int> mono;
		for(int i=0;i<=n;i++){
				while(mono.size()){
					if(arr[mono.top()]>arr[i]) break;
					mono.pop();
				}
				fromrsafe[i] = {((mono.empty())?(-1):(mono.top()+1)),i};
				mono.push(i);
		}
		vector<int> fromlsafe(n+1,0);
		fromlsafe[n] = (arr[n]>=arr[n-1])?(n):(n-1);
		while(mono.size()) mono.pop();
		for(int i=n-1;i>=0;i--){
			while(mono.size()){
				if(arr[mono.top()]<arr[i]) break;
				mono.pop();
			}
			fromlsafe[i+1] = (mono.empty())?(n+1):(mono.top());
			mono.push(i);
		}
		sort(fromrsafe.begin(),fromrsafe.end());
		int rhead=0;
		bit bin;
		bin.init();
		int ans=0;
		for(int i=1;i<=n;i++){
			while(rhead<=n && fromrsafe[rhead].first<i){
				bin.add(fromrsafe[rhead].second,fromrsafe[rhead].second);
				rhead++;
			}
			
			int r  = bin.query(fromlsafe[i]-1);
			ans = max(ans,r-i+1);	
		}
		W(ans);


	}

	fwrite(outbuf,1,outp,stdout);
	return 0;
}
