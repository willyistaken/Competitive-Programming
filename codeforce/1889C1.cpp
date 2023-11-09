#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
struct range{
	int l,r;
	int tcnt = 0;
};

struct segtree{
	vector<int> arr;
	int s;
	void init(int _s){
		arr.resize(2*_s);
		s = _s;
	}
	void modify(int ind,int v){
		ind +=s;
		while(ind){
			arr[ind] = max(arr[ind],v);
			ind>>=1;
		}
	}
	int query(int l,int r){
		l+=s;r+=s;
		int ans = 0;
		while(l<r){
			if(l&1) ans = max(ans,arr[l++]);
			if(r&1) ans = max(ans,arr[--r]);
			l>>=1;r>>=1;
		}
		return ans;
	}
};
struct segtree2{
	vector<int> arr;	
	vector<int> tag;
	int s;
	void init(int _s){
		s = _s;	
		arr.resize(4*s);
		tag.resize(4*s);
	}
	void push(int ind){
		if(2*ind+1>=4*s) return ;
		if(tag[ind]){
			arr[2*ind]+=tag[ind];
			arr[2*ind+1]+=tag[ind];
			tag[ind]=0;
		}
	}
	void modify(int ind,int L,int R,int l,int r,int v){
		if(l==r) return;
		push(ind);
		if(l==L && r==R){
			arr[ind]+=v;
			tag[ind]+=v;
			return ;
		}
		int M = (L+R)/2;
		if(r<=M) modify(2*ind,L,M,l,r,v);
		else if(l>=M) modify(2*ind+1,M,R,l,r,v);
		else{
			modify(2*ind,L,M,l,M,v);
			modify(2*ind+1,M,R,M,r,v);
		}
		if(2*ind+1<4*s) arr[ind] = max(arr[2*ind],arr[2*ind+1]);
	}
	int query(int ind,int L,int R,int l,int r){
		if(l==r) return 0;
		push(ind);
		if(l==L && r==R){
			return arr[ind]	;
		}
		int M = (L+R)/2;
		if(r<=M) return query(2*ind,L,M,l,r);
		else if(l>=M) return query(2*ind+1,M,R,l,r);
		else{
			return max(query(2*ind,L,M,l,M),query(2*ind+1,M,R,M,r));
		}
	}
		
} ;

vector<range> keeper;
pair<int,int> get(int ind){
	int K = keeper.size();
	int l = -1;int r = K;
	while(r-l>1){
		int mid = (l+r)/2;
		if(keeper[mid].r>=ind) r = mid;
		else l = mid;
	}
	int rr = r;
	l = -1; r = K;
	while(r-l>1){
		int mid = (l+r)/2;
		if(keeper[mid].l<=ind) l = mid;
		else r = mid;
	}
	//cout<<ind<<" "<<l<<"-"<<rr<<"\n";
	if(rr>l) return {0,-1};
	return {rr,l};
}
void solve(){
	keeper.clear();
	int n,m,k;cin>>n>>m>>k;
	vector<range> rg;								
	vector<int> thick(n+2,0);
	vector<int> ocnt(n+2,0);
	vector<int> tcnt(n+2,0);
	rg.resize(m);
	for(int i=0;i<m;i++){
		cin>>rg[i].l>>rg[i].r;
		thick[rg[i].l]++;
		thick[rg[i].r+1]--;
	}
	int zcnt = 0;
	for(int i=1;i<=n;i++){
		thick[i] += thick[i-1];
		if(thick[i]==0) zcnt++;
		if(thick[i]==1) ocnt[i]++;
		if(thick[i]==2) tcnt[i]++;
	}
	for(int i=1;i<=n;i++){
		ocnt[i]+=ocnt[i-1];
		tcnt[i]+=tcnt[i-1];
	}
	int ans = 0;
	sort(rg.begin(),rg.end(),[](const range &a,const range &b){return (a.r==b.r)?(a.l>b.l):(a.r<b.r);});
	for(int i=0;i<m;i++) rg[i].tcnt = tcnt[rg[i].r]-tcnt[rg[i].l-1];
	segtree sg;
	sg.init(n+1);
	for(int i=0;i<m;i++){
		while(keeper.size()){
			int g = keeper.size();
			if(keeper[g-1].l>=rg[i].l) keeper.pop_back();
			else break;
		}
		keeper.push_back(rg[i]);
		ans = max(ans,ocnt[rg[i].r]-ocnt[rg[i].l-1]+sg.query(rg[i].l,n+1));
		sg.modify(rg[i].l,rg[i].tcnt);
	}
	int l = 0;int r = 0;
	segtree2 sg2;
	int K = keeper.size();
	sg2.init(K);
	for(int i=0;i<K;i++){
		auto x = keeper[i];
		while(r<x.r){
			r++;
			if(thick[r]==2){
				pair<int,int> aran = get(r);
				sg2.modify(1,0,K,aran.first,aran.second+1,1);
	//			cout<<r<<"+1>>"<<aran.first<<" "<<aran.second<<"\n";
			}
		}
		while(l<x.l){
			if(l && thick[l]==2){
				pair<int,int> aran = get(l);
				sg2.modify(1,0,K,aran.first,aran.second+1,-1);
	//			cout<<l<<"-1>>"<<aran.first<<" "<<aran.second<<"\n";
			}
			l++;
		}
		//cout<<ocnt[x.r]-ocnt[x.l-1]<<" "<<sg2.query(1,0,K,0,i)<<"t\n";
		ans = max(ans,ocnt[x.r]-ocnt[x.l-1]+sg2.query(1,0,K,0,i));
		sg2.modify(1,0,K,i,i+1,ocnt[x.r]-ocnt[x.l-1]);
	}
	cout<<ans+zcnt<<"\n";
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
