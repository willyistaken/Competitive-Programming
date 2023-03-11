#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct SEG{
	vector<pair<int,int> > arr;
	void init(int s){
		arr.resize(4*s);
	}
	void set(int x,int L,int R,int ind,pair<int,int> v){
		if(R-L<=1) {
			arr[ind] = max(v,arr[ind]);
			return ;
		}
		int M = (L+R)/2;
		if(x<M) set(x,L,M,2*ind,v);
		else set(x,M,R,2*ind+1,v);
		arr[ind] = max(arr[2*ind],arr[2*ind+1]);
	}
	pair<int,int> query(int l,int r,int L,int R,int ind){
		if(l==L && r==R) return arr[ind];
		int M = (L+R)/2;
		if(r<=M) return query(l,r,L,M,2*ind);
		else if(l>=M) return query(l,r,M,R,2*ind+1);
		return max(query(l,M,L,M,2*ind),query(M,r,M,R,2*ind+1));
	}
} seg;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<int> a(n);
	vector<int> d;
	map<int,int> mp;
	for(int i=0;i<n;i++){
		cin>>a[i];
		d.push_back(a[i]);
		mp[a[i]]=i;
	}
	sort(d.begin(),d.end());
	d.resize(unique(d.begin(),d.end())-d.begin());
	vector<int> b(n);
	for(int i=0;i<n;i++){
		int k;cin>>k;
		int g =mp[k]; 
		b[g] = i;
	}
	int arr[n];
	pair<int,int> ans[n];			
	for(int i=0;i<n;i++){
		arr[i] = n-b[n-i-1]-1;
		ans[i].second = a[n-i-1];
	}
	seg.init(n);
	ans[0].first=1;
	int prev[n];
	prev[0]=-1;
	int maxans = 0;
	seg.set(arr[0],0,n,1,ans[0]);
	for(int i=1;i<n;i++){
		prev[i]=-1;
		auto maxn = seg.query(0,arr[i],0,n,1);
		ans[i].first = maxn.first+1;
		if(ans[i]>ans[maxans]) maxans = i;
		prev[i] = (ans[i].first==1)?(-1):(n-mp[maxn.second]-1);
		seg.set(arr[i],0,n,1,ans[i]);
	}
	int g = ans[maxans].first;
	for(int i=0;i<g;i++){
		cout<<ans[maxans].second<<" ";
		maxans = prev[maxans];
	}
	return 0;
}
