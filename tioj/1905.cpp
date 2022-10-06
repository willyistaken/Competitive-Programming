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
const int S = 1e5;
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

int n,k,f;
vector<int> arr;
vector<int> d;

struct seg{
	vector<int> arr;
	int s;
	void init(int g){
		s = g;
		arr.resize(2*s,INT_MAX);
	}

	void modify(int ind,int v){
		ind+=s;
		arr[ind]=min(arr[ind],v);
		ind>>=1;
		while(ind){
			arr[ind] = min(arr[2*ind],arr[2*ind+1]);
			ind>>=1;
		}
	}
	
	int query(int l,int r){
		int ans = INT_MAX;
		l+=s;r+=s;
		while(l<r){
			if(l&1) ans = min(ans,arr[l++]);
			if(r&1) ans = min(ans,arr[--r]);
			l>>=1;r>>=1;
		}
		return ans;
	}
};

struct Q{
	int l,r;
	int id;
	int ans;
};

int getid(int v){
	return lower_bound(d.begin(),d.end(),v)-d.begin();
}

int main(){
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	n = R();
	arr.resize(n);
	for(int i=0;i<n;i++) arr[i] = R();
	d = arr;
	sort(d.begin(),d.end());
	d.resize(unique(d.begin(),d.end())-d.begin());
	f = R();
	Q q[f];
	for(int i=0;i<f;i++){
		cin>>q[i].l>>q[i].r;
		q[i].l--;q[i].r--;
		q[i].id = i;
	}
	sort(q,q+f,[](const Q &a,const Q &b){return a.r<b.r;});
	
	seg mindis;mindis.init(n);
	seg update;update.init(d.size());
	update.modify(getid(arr[0]),-0);	
	int qhead=0;
	for(int i=1;i<n;i++){
		// smaller side
		int c=0;
		int u;
		while(arr[i]-c>1 && (u = update.query(getid(c),getid(arr[i])+1) )<=0){
			u = -u;
			mindis.modify(u,arr[i]-arr[u]);
			c = (arr[u]+((arr[i]-arr[u])/2))+((arr[i]-arr[u])&1);
		}
		// larger side
		c = INT_MAX;
		while( c-arr[i]>1 &&(u = update.query(getid(arr[i]),getid(c)))<=0){
			u = -u;
			mindis.modify(u,arr[u]-arr[i]);
			c = (arr[i]+((arr[u]-arr[i])/2));
		}
		
		// update
		update.modify(getid(arr[i]),-i);
		// getans 
		while(qhead<f && q[qhead].r==i){
			q[qhead].ans = mindis.query(q[qhead].l,q[qhead].r);
			qhead++;
		}
	}
	sort(q,q+f,[](const Q &a,const Q &b){return a.id<b.id;});
	for(int i=0;i<f;i++){
		W(q[i].ans);
	}
	fwrite(outbuf, 1, outp, stdout);


}
