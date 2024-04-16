#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 1e6+5;
int r[N];
int l[N];
int p[N];
int query(int a){
	if(p[a]==a) return p[a];
	p[a] = query(p[a]);
	return p[a];
}

void join(int a,int b){
	a = query(a);b=query(b);
	l[a] = min(l[a],l[b]);
	r[a] = max(r[a],r[b]);
	p[b] = a;
}

struct SEG{
	vector<int> arr;
	int n;
	void init(int _n){
		 n = _n;
		 arr.resize(2*n,0);
	}
	void modify(int l,int r,int v){
		l+=n;
		r++;
		r+=n;
		while(l<r){
			if(l&1){arr[l] = max(arr[l],v);l++;}
			if(r&1){r--;arr[r] = max(arr[r],v);}
			l>>=1;
			r>>=1;
		}
	}
	int query(int x){
		x+=n;
		int a = 0;
		while(x){
			a = max(a,arr[x]);
			x>>=1;
		}
		return a;
	}
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<ll> a(n+1);
	vector<ll> b(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	vector<int> ord;
	for(int i=0;i<=n+1;i++){
		r[i]=i;
		l[i]=i;
		p[i]=i;
	}
	for(int i=0;i<=n;i++) ord.push_back(i);
	sort(ord.begin(),ord.end(),[&](const int &x,const int &y){return b[x]<b[y];});
	SEG seg;		
	seg.init(n+2);
	for(auto i : ord){
		int x = query(i);
		int y = query(i+1);
		if(l[x]>0){
			int f = max(0LL,b[i]-(a[r[x]]-a[l[x]-1]));
			seg.modify(l[x],r[x],f);
		}
		if(r[y]<n+1){
			int f = max(0LL,b[i]-(a[r[y]]-a[l[y]-1]));	
			seg.modify(l[y],r[y],f);
		}
		join(x,y);
	}
	for(int i=1;i<=n;i++){
		cout<<seg.query(i)<<" ";
	}
	cout<<"\n";
	return 0;
}
