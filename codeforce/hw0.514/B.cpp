#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct BIT{
	int n;
	vector<int> arr;
	void init(int _n){
		n = _n;
		arr.resize(n+1,0);
	}
	void modify(int x,int ind){
		while(ind<=n){
			arr[ind]^=x;
			ind+=(ind&-ind);
		}
	}
	int query(int ind){
		int ret = 0;
		while(ind){
			ret^=arr[ind];
			ind-=(ind&-ind);
		}
		return ret;
	}
};


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;	
	BIT bit;		
	bit.init(n);
	vector<int> arr(n+1,0);
	vector<int> pre(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		pre[i] = pre[i-1]^arr[i];
	}
	int q;cin>>q;
	vector<pair<int,int> > queries(q);
	for(int i=0;i<q;i++){
		cin>>queries[i].first>>queries[i].second;
	}
	vector<int> ans(q,0);
	vector<int> ord(q);
	for(int i=0;i<q;i++) ord[i]=i;
	sort(ord.begin(),ord.end(),[&](const int a,const int b){return queries[a].second<queries[b].second;});
	map<int,int> mp;
	int head = 0;
	for(int r=1;r<=n;r++){
		int l = 1;	
		if(mp.count(arr[r])){
			l = mp[arr[r]]+1;
		}
		mp[arr[r]]=r;
		bit.modify(arr[r],l);
		bit.modify(arr[r],r+1);
		while(head<q && queries[ord[head]].second==r){
			auto [ql,qr] = queries[ord[head]];
			ans[ord[head]] = pre[qr]^pre[ql-1]^bit.query(ql);
			head++;
		}
	}
	for(int i=0;i<q;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}
