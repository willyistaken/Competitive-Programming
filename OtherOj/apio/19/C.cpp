#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
struct Q{
	int l;
	int r;
	int t;
	bool type;
	int ans;
	Q(int _l=0,int _r=0,int _t=0,bool _type=0,int _ans=0):l(_l),r(_r),t(_t),type(_type),ans(_ans){}
};
struct BIT{
	int n;
	vector<ll> arr;
	void init(int _n){
		n = _n;	
		arr.resize(n+1,0);
	}
	void add(int x,int v){
		while(x<=n){
			arr[x]+=v;
			x+=(x&-x);
		}
	}
	ll query(int x){
		ll ans = 0;
		while(x){
			ans+=arr[x];
			x-=(x&-x);
		}
		return ans;
	}
};
vector<Q> qvec;
BIT Lsum;
bool ch(int l,int r,int llim,int rlim){
	if(l>=llim) return 1;
	if(r>=rlim) return 0;
	return qvec[r].l<qvec[l].l;
}
void solve(int l,int r){
	if(r-l<=1) return;
	int M = (l+r)/2;
	solve(l,M);
	solve(M,r);
	int lhead = l;
	int rhead = M;
	vector<Q> temparr;
	vector<pair<int,ll> > aq;
	for(int tt=0;tt<r-l;tt++){
		if(ch(lhead,rhead,M,r)){
			if(qvec[rhead].type){
				qvec[rhead].ans+=Lsum.query(qvec[rhead].r);
			}
			temparr.push_back(qvec[rhead]);
			rhead++;
		}else{
			if(!qvec[lhead].type){
				Lsum.add(qvec[lhead].r,qvec[lhead].ans);
				aq.emplace_back(qvec[lhead].r,qvec[lhead].ans);
			}
			temparr.push_back(qvec[lhead]);
			lhead++;
		}
	}
	for(auto i : aq){
		Lsum.add(i.first,-i.second);
	}
	for(int tt=0;tt<r-l;tt++){
		qvec[l+tt] = temparr[tt];
	}
}


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,q;cin>>n>>q;				
	BIT arr;
	arr.init(n);
	string s;cin>>s;		
	for(int i=0;i<n;i++){
		if(s[i]=='1') arr.add(i+1,1);
	}
	for(int i=1;i<=q;i++){
		string ts;cin>>ts;
		if(ts[0]=='q'){
			Q temp;
			cin>>temp.l>>temp.r;
			temp.r--;
			temp.t=i;
			temp.type=1;
			temp.ans=0;
			if(arr.query(temp.r)-arr.query(temp.l-1)==temp.r-temp.l+1) temp.ans=i;
			qvec.push_back(temp);
		}else{
			int x;cin>>x;
			int m = (arr.query(x)-arr.query(x-1))?(1):(-1);
			int ql=0;int qr=x;int pl=x;int pr=n+1;
			while(qr-ql>1){
				int mid = (qr+ql)/2;
				if(arr.query(x-1)-arr.query(mid-1)==x-mid) qr=mid;
				else ql=mid;
			}
			while(pr-pl>1){
				int mid = (pr+pl)/2;
				if(arr.query(mid)-arr.query(x)==mid-x) pl=mid;
				else pr=mid;
			}
			qvec.emplace_back(qr,x,i,0,i*m);
			qvec.emplace_back(x+1,x,i,0,-1*i*m);
			qvec.emplace_back(qr,pl+1,i,0,-1*i*m);
			qvec.emplace_back(x+1,pl+1,i,0,i*m);
			arr.add(x,-m);
		}
	}
	Lsum.init(n+1);
	int N = qvec.size();
	solve(0,N);
	sort(qvec.begin(),qvec.end(),[](const Q &a,const Q &b){return a.t<b.t;});
	for(auto i : qvec){
		if(i.type) cout<<i.ans<<"\n";
	}
	return 0;
}
/*
5 5
00011
query 3 6
toggle 5
query 4 5
toggle 5
query 5 6

0
3
3
*/
