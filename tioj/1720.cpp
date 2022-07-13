#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct points{
	int s;
	int r;
};
int e;
struct bit{
	vector<int> arr;
	void init(){
		arr.resize(e+1);
		fill(arr.begin(),arr.end(),0);
	}
	void add(int ind){
		while(ind<=e){
			arr[ind]+=1;
			ind+=(ind & -ind);
		}
	}

	int query(int ind){
		int r=0;
		while(ind){
			r+=arr[ind];
			ind-=(ind & -ind);
		}
		return r;
	}


};
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int k,m;cin>>k>>m;
	points so[k];
	for(int i=0;i<k;i++) cin>>so[i].s;
	for(int i=0;i<k;i++) cin>>so[i].r;
	sort(so,so+k,[](const points &a,const points &b){return ((a.s==b.s)?(a.r<b.r):(a.s<b.s));});
	vector<int> arr;
	vector<int> cc;
	for(int i=0;i<k;i++) {
		arr.push_back(so[i].r);
		cc.push_back(so[i].r);
	}
	sort(cc.begin(),cc.end(),greater<int>());
	e = unique(cc.begin(),cc.end())-cc.begin();
	bit fenwick;
	fenwick.init();
	ll sum=0;
	for(auto i : arr){
		int q = lower_bound(cc.begin(),cc.begin()+e,i,greater<int>())-cc.begin();
		int a = upper_bound(cc.begin(),cc.begin()+e,i,greater<int>())-cc.begin();
		sum+=fenwick.query(q);
		fenwick.add(a);
	}
	cout<<sum<<"\n";

	return 0;
}
