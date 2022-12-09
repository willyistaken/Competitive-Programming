#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct bit{
	vector<int> arr;
	int s;
	void init(int f){
		s = f;
		arr.resize(s+1,0);
		fill(arr.begin(),arr.end(),0);
	}
	void modify(int ind,int v){
		while(ind<=s){
			arr[ind]+=v;
			ind+=(ind & -ind);
		}
	}
	int query(int ind){
		int r = 0;
		while(ind){
			r+=arr[ind];
			ind-=(ind & -ind);
		}
		return r;
	}
};

struct T{
	int l;
	int r;
	int ans;
	int t;
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	bit fen;
	int n;cin>>n;
	vector<int> d;
	vector<T> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i].l>>arr[i].r;
		arr[i].t = i;
		d.push_back(arr[i].l);
		d.push_back(arr[i].r);
	}
	sort(d.begin(),d.end());
	d.resize(unique(d.begin(),d.end())-d.begin());
	sort(arr.begin(),arr.end(),[](const T &a,const T &b){return (a.l==b.l)?(a.r<b.r):(a.l>b.l);});
	fen.init(d.size());
	for(int i=0;i<n;i++){
		int p = lower_bound(d.begin(),d.end(),arr[i].r)-d.begin()+1;
		arr[i].ans = fen.query(p);
		fen.modify(p,1);
	}
	sort(arr.begin(),arr.end(),[](const T &a,const T &b){return a.t<b.t;});
	for(int i=0;i<n;i++) cout<<arr[i].ans<<" \n"[i==n-1];
	fen.init(d.size());
	sort(arr.begin(),arr.end(),[](const T &a,const T &b){return (a.l==b.l)?(a.r>b.r):(a.l<b.l);});
	for(int i=0;i<n;i++){
		int p = lower_bound(d.begin(),d.end(),arr[i].r)-d.begin()+1;
		arr[i].ans = (i)-fen.query(p-1);
		fen.modify(p,1);
	}
	sort(arr.begin(),arr.end(),[](const T &a,const T &b){return a.t<b.t;});
	for(int i=0;i<n;i++) cout<<arr[i].ans<<" \n"[i==n-1];
	return 0;
}
