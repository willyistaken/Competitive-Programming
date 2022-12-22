#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


struct BIT{
	vector<int> arr;
	int _n;
	void init(int s){
		arr.resize(s+1,0);
		_n = s;
	}
	void modify(int ind,int v){
		while(ind<=_n){
			arr[ind]+=v;
			ind+=(ind & -ind);
		}
	}
	int query(int ind){
		int ans = 0;
		while(ind){
			ans+=arr[ind];
			ind-=(ind & -ind);
		}
		return ans;
	}

};
struct qe{
	int l;
	int r;
	int ans;
	int t;
};
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	BIT bit;
	int n,q;cin>>n>>q;
	bit.init(n);
	int arr[n+1];
	for(int i=1;i<=n;i++) cin>>arr[i];
	qe query[q];	
	for(int i = 0;i<q;i++){
		cin>>query[i].l>>query[i].r;
		query[i].t = i;
	}
	sort(query,query+q,[](const qe a,const qe b){return a.r<b.r;});
	int cur = 0;
	map<int,int> prev;
	for(int i=0;i<q;i++){
		while(cur<query[i].r){
			cur++;
			bit.modify(prev[arr[cur]]+1,1);
			bit.modify(cur+1,-1);
			prev[arr[cur]]=cur;
		}
		query[i].ans = bit.query(query[i].l);
	}
	sort(query,query+q,[](const qe a,const qe b){return a.t<b.t;});
	for(int i=0;i<q;i++) cout<<query[i].ans<<"\n";
	return 0;
}
