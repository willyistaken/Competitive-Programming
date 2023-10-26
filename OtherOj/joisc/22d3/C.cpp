#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
// 0-base
#define inf 100000000000000
ll suma,sumb;
vector<int> d;
inline int ind(int X){
	return lower_bound(d.begin(),d.end(),X)-d.begin();
}

struct Data{
	ll dp[2][2] = {{0,-inf},{-inf,0}};
};
Data operator+(Data &a,Data &b){
	Data ret;
	ret.dp[0][0]= max(a.dp[0][0]+b.dp[0][0],a.dp[0][1]+b.dp[1][0]);
	ret.dp[0][1]= max(a.dp[0][0]+b.dp[0][1],a.dp[0][1]+b.dp[1][1]);
	ret.dp[1][0]= max(a.dp[1][0]+b.dp[0][0],a.dp[1][1]+b.dp[1][0]);
	ret.dp[1][1]= max(a.dp[1][0]+b.dp[0][1],a.dp[1][1]+b.dp[1][1]);
	return ret;
}

struct SegTree{
	int s;
	struct node{
		Data dt;
		ll tag[2]={0,0};
		void add_tag(int v,int o){
			dt.dp[o][o^1]+=v;
			tag[o]+=v;
		}
	};
	vector<node> arr;
	void init(int _s){
		s = _s;
		arr.resize(4*s);
	}
	void pull(int ind){
		if(2*ind+1>=4*s) return;
		arr[ind].dt = arr[2*ind].dt+arr[2*ind+1].dt;
	}
	void push(int ind){
		if(2*ind+1>=4*s) return;
		for(int o=0;o<2;o++){
			if(arr[ind].tag[o]){
				arr[2*ind].add_tag(arr[ind].tag[o],o);
				arr[2*ind+1].add_tag(arr[ind].tag[o],o);
				arr[ind].tag[o]=0;
			}
		}
	}
	void update(int ind,int v,int l,int r,int L,int R,int o){	
		if(l<=r) return;
		//cout<<l<<" "<<r<<".."<<L<<" "<<R<<endl;
		push(ind);
		if(l==L && r==R){
			arr[ind].add_tag(v,o);
			return;
		}
		int mid = (L+R)/2;
		if(r<=mid) update(2*ind,v,l,r,L,mid,o);
		else if(l>=mid) update(2*ind+1,v,l,r,mid,R,o);
		else{
			update(2*ind,v,l,mid,L,mid,o);
			update(2*ind+1,v,mid,r,mid,R,o);
		}
		pull(ind);
	}
	ll get(){
		push(1);
		pull(1);
		//return max(max(arr[1].dt.dp[0][0],arr[1].dt.dp[1][0])+a,max(arr[1].dt.dp[0][1],arr[1].dt.dp[1][1])+b);
		return max(max(arr[1].dt.dp[1][1],arr[1].dt.dp[0][1])+sumb,max(arr[1].dt.dp[0][0],arr[1].dt.dp[1][0])+suma);
	}
} seg;


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,L;			
	cin>>n>>L;
	vector<int> T(n),X(n),A(n);
	for(int i=0;i<n;i++) {
		cin>>T[i]>>X[i]>>A[i];
		d.push_back(X[i]);
	}
	sort(d.begin(),d.end());
	d.resize(unique(d.begin(),d.end())-d.begin());
	int N = d.size();
	seg.init(N);
	for(int i=0;i<n;i++){
		if(T[i]==1)	{
			suma+=A[i];
			int r = ind(X[i]);
			int l = ind(X[i]-L);
			seg.update(1,A[i],r,N,0,N,0);
			seg.update(1,-A[i],r,N,0,N,1);
			seg.update(1,-A[i],l,r,0,N,1);
		}else{
			sumb+=A[i]	;
			int r = ind(X[i]);
			int l = ind(X[i]-L);
			seg.update(1,A[i],r,N,0,N,1);
			seg.update(1,-A[i],r,N,0,N,0);
			seg.update(1,-A[i],l,r,0,N,0);
		}
		cout<<suma+sumb-seg.get()<<"\n";
	}
	return 0;
}
