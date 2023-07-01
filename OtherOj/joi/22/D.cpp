#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n,k;
vector<int> maxr;
vector<int> minl;

void setr(int l,int r,int v){
	l+=n;r+=n;
	while(r>l){
		if(l&1) {maxr[l] = max(maxr[l],v);l++;}
		if(r&1) {r--;maxr[r] = max(maxr[r],v);}
		l>>=1;r>>=1;
	}
}

void setl(int l,int r,int v){
	l+=n;r+=n;
	while(r>l){
		if(l&1) {minl[l] = min(minl[l],v);l++;}
		if(r&1) {r--;minl[r] = min(minl[r],v);}
		l>>=1;r>>=1;
	}
}

struct segtree{
	vector<pair<int,int> > seg;
	void init(){
		seg.resize(2*n);
	}
	pair<int,int> mix(pair<int,int> a,pair<int,int> b){
		return {min(a.first,b.first),max(a.second,b.second)};
	}
	void built(int ind){
		if(2*ind+1>=2*n) return ;
		built(2*ind);built(2*ind+1);
		seg[ind] = mix(seg[2*ind],seg[2*ind+1]);
	}
	void modify(int ind,pair<int,int> v){
		ind+=n;
		while(ind){
			seg[ind] = mix(seg[ind],v);
			ind>>=1;
		}
	}
	
	pair<int,int> query(int l,int r){
		l+=n;r+=n;
		pair<int,int> ans = {1e9,-1};
		while(r>l){
			if(l&1) ans = mix(ans,seg[l++]);
			if(r&1) ans = mix(ans,seg[--r]);
			l>>=1;r>>=1;
		}
		return ans;
	}
};

vector<segtree> jump;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	int m;cin>>m;
	maxr.resize(2*n,0);
	minl.resize(2*n,0);
	for(int i=0;i<n;i++){
		maxr[i] = -1;
		minl[i] = 1e9;
		maxr[i+n]=i;
		minl[i+n]=i;
	}
	jump.resize(18);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		a--;b--;
		if(a<b){
			setr(a,min(a+k,b+1),b);
		}else{
			setl(max(a-k+1,b),a+1,b);
		}
	}
	for(int i=0;i<n;i++){
		int g = i+n;	
		while(g){
			maxr[i+n] = max(maxr[i+n],maxr[g]);
			minl[i+n] = min(minl[i+n],minl[g]);
			g>>=1;
		}
	}

	jump[0].init();
	for(int i=0;i<n;i++){
		jump[0].seg[i+n] = {minl[i+n],maxr[i+n]};
	}
	jump[0].built(1);
	for(int j=1;j<18;j++){
		jump[j].init();
		for(int i=0;i<n;i++){
			pair<int,int> prevrange = jump[j-1].seg[i+n];
			jump[j].seg[i+n] = jump[j-1].query(prevrange.first,prevrange.second+1);
		}
		jump[j].built(1);
	}
/*	for(int j=0;j<18;j++){
		for(int i=0;i<n;i++){
			cout<<jump[j].seg[i+n].first<<"~"<<jump[j].seg[i+n].second<<"|";
		}
		cout<<"\n";
	}*/
	int q;cin>>q;
	while(q--){
		int a,b;cin>>a>>b;
		a--;b--;
		ll ans =0;
		if(b>jump[17].seg[a+n].second || b<jump[17].seg[a+n].first){cout<<-1<<"\n";continue;}
		int l = a;int r = a;
		for(int p=17;p>=0;p--){
			pair<int,int> range = jump[p].query(l,r+1);
			if(b<range.first || b>range.second){
				l = range.first;
				r = range.second;
				ans+=(1<<p);
			}
		}
		cout<<ans+1<<"\n";
	}
	return 0;
}
