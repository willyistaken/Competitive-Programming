#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define int ll
void zalgo(int *z,string s){
	fill(z,z+s.size(),0);
	for(int i = 1,l = 0, r = 0;i<s.size();i++){
		if(i<=r) z[i] = min(z[i-l],r-i+1);
		while(i+z[i]<s.size() && s[i+z[i]]==s[z[i]]) z[i]++;
		if(i+z[i]-1>r) l = i,r = i+z[i]-1;
	}
}

struct sg{
	struct node{
		int v = 0;
		int tag = 0;
		int len = 1;
		void apply(int u){
			v+=len*u;
			tag+=u;
		}
	};
	vector<node> arr;
	int n;
	void build(){
		for(int i = n-1;i>=1;i--){
			arr[i].len = arr[2*i].len+arr[2*i^1].len;
		}
	}
	void init(int s){
		n = s;
		arr.resize(2*s);
		build();
	}
	void pull(int ind){
		if(ind<=1) return;
		pull(ind>>1);
		ind>>=1;
		arr[2*ind].apply(arr[ind].tag);
		arr[2*ind^1].apply(arr[ind].tag);
		arr[ind].tag = 0;
	}
	void push(int ind){
		ind>>=1;
		while(ind){
			arr[ind].v = arr[2*ind].v+arr[2*ind^1].v;
			int k = arr[ind].tag;
			arr[ind].apply(k);
			arr[ind].tag = k;
			ind>>=1;
		}
	}
	void add(int l,int r,int v){
		l+=n;r+=n;
		pull(l);
		pull(r-1);
		int tl = l;
		int tr = r;
		while(l<r){
			if(l&1) arr[l++].apply(v);
			if(r&1) arr[--r].apply(v);
			l>>=1;r>>=1;
		}
		push(tl);
		push(tr-1);
	}
	int query(int l,int r){
		l+=n;r+=n;
		pull(l); pull(r-1);
		int ans = 0;
		while(l<r){
			if(l&1) ans+=arr[l++].v;		
			if(r&1) ans+=arr[--r].v;
			l>>=1;r>>=1;
		}
		return ans;
	}
} seg;

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	string a,b;cin>>a>>b;
	reverse(b.begin(),b.end());
	string s;cin>>s;	
	int z[n+m+1];
	zalgo(z,s+"#"+a);			
	vector<int> aarr(n);
	for(int i=0;i<n;i++) aarr[i] = (z[i+m+1]==m)?(m-1):(z[i+m+1]);
	reverse(s.begin(),s.end());	
	zalgo(z,s+"#"+b);
	vector<int> barr(n);
	for(int i=0;i<n;i++) barr[n-i-1] = (z[i+m+1]==m)?(m-1):(z[i+m+1]);
	seg.init(max(n,m)+5);					
	ll ans = 0;	
	for(int i = 0;i<min(m-1,n);i++){
		seg.add(0,barr[i]+1,1);
	}
	for(int i = 0;i<n;i++){
		ans+=seg.query(m-aarr[i],max(m,n));		
		seg.add(0,barr[i]+1,-1);
		if((i+m-1)<n) seg.add(0,barr[i+m-1]+1,1);
	}
	cout<<ans<<"\n";
	return 0;
}
