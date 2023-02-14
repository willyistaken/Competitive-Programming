#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct seg{
	struct node{
		int sum = 0;
		int tag = 0;
		int len = 1;
		void set(bool k){
			if(k) sum =  len;
			else sum = 0;
			tag = k?(1):(-1);
		}
	};
	vector<node> arr;
	void init(int n){
		arr.resize(4*n);
	}
	void push(int ind){
		if(2*ind+1>=arr.size()) return;
		if(arr[ind].tag){
			if(arr[ind].tag>0) {
				arr[2*ind].set(1);
				arr[2*ind+1].set(1);
			}else{
				arr[2*ind].set(0);
				arr[2*ind+1].set(0);
			}
		}
		arr[ind].tag = 0;
		arr[ind].sum = arr[2*ind].sum+arr[2*ind+1].sum;
	}
	void set(int l,int r,int L,int R,bool k,int ind){
		push(ind);	
		if(l==L && r==R) {
			arr[ind].set(k);
			return;
		}
		int M = (L+R)/2;	
		if(r<=M) set(l,r,L,M,k,2*ind);
		else if(l>=M) set(l,r,M,R,k,2*ind+1);
		else{
			set(l,M,L,M,k,2*ind);
			set(M,r,M,R,k,2*ind+1);
		}
		arr[ind].sum = arr[2*ind].sum+arr[2*ind+1].sum;
		return;
	}
	int query(int l,int r,int L,int R,int ind){
		if(l==L && r==R) return arr[ind].sum;
		push(ind);
		int M = (L+R)/2;
		if(r<=M) return query(l,r,L,M,2*ind);
		else if(l>=M) return query(l,r,M,R,2*ind+1);
		else{
			return query(l,M,L,M,2*ind)+query(M,r,M,R,2*ind+1);
		}
	}
	void built(int cur,int l,int r){
		arr[cur].len = r-l;
		if(r-l<=1) return;
		int m = (l+r)/2;
		built(2*cur,l,m);
		built(2*cur+1,m,r);
	}
};

void solve(){
	int n,m;cin>>n>>m;
	string s,e;cin>>s>>e;
	seg seg;
	seg.init(n);
	seg.built(1,0,n);
	for(int i=0;i<n;i++){
		if(e[i]=='1') seg.set(i,i+1,0,n,1,1);
	}
	pair<int,int> q[m];
	for(int i=m-1;i>=0;i--){
		cin>>q[i].first>>q[i].second;
	}
	for(int i=0;i<m;i++){
		int l = q[i].first;
		int r = q[i].second;
		int ocnt = seg.query(l-1,r,0,n,1);
		//cout<<l<<" "<<r<<" "<<ocnt<<"\n";
		int len = r-l+1;
		if(2*ocnt==len){
			cout<<"No\n";
			return ;
		}
		bool maj = (2*ocnt>len);
		if(maj) seg.set(l-1,r,0,n,1,1);
		else seg.set(l-1,r,0,n,0,1);
	}
	for(int i=0;i<n;i++){
		int g = seg.query(i,i+1,0,n,1);
		if(s[i]-'0'!=g){
			cout<<"NO\n";
			return ;
		}
	}
	cout<<"YES\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
