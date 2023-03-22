#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct BIT{
	vector<int> arr;
	int n;
	void init(int s){
		n = s;
		arr.resize(n+1,0);
	}

	void update(int i,int v){
		while(i){
			arr[i] = max(arr[i],v);
			i-=(i&-i);
		}
	}

	int query(int i){
		int r = 0;
		while(i<=n){
			r = max(r,arr[i]);
			i+=(i&-i);
		}
		return r;
	}
} bit;

stack<pair<int,int> > stk;

struct query{
	int l;
	int r;
	int k;
	int t;
	bool ans;
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;	
	bit.init(n);
	int arr[n+1];
	for(int i=1;i<=n;i++) cin>>arr[i];
	vector<query> qu(q);
	for(int i=0;i<q;i++){
		cin>>qu[i].l>>qu[i].r>>qu[i].k;
		qu[i].t = i;
	}
	sort(qu.begin(),qu.end(),[](const query &a,const query &b){return a.r<b.r;});
	int p = 0;	
	for(int i=1;i<=n;i++){
		while(stk.size() && stk.top().second<=arr[i]) stk.pop();
		if(stk.size()) bit.update(stk.top().first,arr[i]+stk.top().second);
		stk.push({i,arr[i]});
		while(p<q && qu[p].r==i){
			qu[p].ans = bit.query(qu[p].l)<=qu[p].k;
			p++;
		}
	}
	sort(qu.begin(),qu.end(),[](const query &a,const query &b){return a.t<b.t;});
	for(int i=0;i<q;i++){
		cout<<qu[i].ans<<'\n';
	}
	
	return 0;
}
