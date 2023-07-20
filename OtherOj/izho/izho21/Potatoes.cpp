#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#include <ext/pb_ds/assoc_container.hpp>
const int N = 2e5+2;

__gnu_pbds::gp_hash_table<int, int> btree[4*N];

struct query{
	int l;
	int r;
	int t;
};

int btreemin[4*N];

struct BIT{
	vector<int> arr;
	void add(int ind,int v){
		//cout<<"adding "<<v<<" in :"<<ind<<"\n";
		while(ind<arr.size()){
			arr[ind]+=v;
			ind+=(ind&-ind);
		}
	}
	int query(int ind){
		//cout<<"query "<<ind<<"\n";
		int ans = 0;
		while(ind){
			ans+=arr[ind];
			ind-=(ind&-ind);
		}
		return ans;
	}
} bit;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	bit.arr.resize(n+1,0);
	ll x,y;cin>>x>>y;
	int arr[n+1];
	for(int i=1;i<=n;i++) cin>>arr[i];
	int q;cin>>q;
	int ans[q];
	query qarr[q];
	for(int i=0;i<q;i++){
		cin>>qarr[i].l>>qarr[i].r;
		qarr[i].t = i;
	}
	sort(qarr,qarr+q,[](const query &a,const query &b){return a.r<b.r;});
	int head = 0;
	for(int i=1;i<=n;i++){
		int ind = 1;	
		int loc = i;	
		bit.add(btreemin[ind]+1,1);
		bit.add(1,-1);
		//cout<<"btree:"<<btree[ind][arr[i]]<<" "<<ind<<" "<<arr[i]<<"\n";
		btreemin[ind] = max(btree[ind][arr[i]],btreemin[ind]);
		btree[ind][arr[i]] = i;
		bit.add(btreemin[ind]+1,-1);
		bit.add(1,1);
		while(2*ind+1<4*n){
			if(loc&1) ind = 2*ind+1;
			else ind = 2*ind;
			bit.add(btreemin[ind]+1,1);
			bit.add(1,-1);
		//	cout<<"btree:"<<btree[ind][arr[i]]<<" "<<ind<<" "<<arr[i]<<"\n";
			btreemin[ind] = max(btree[ind][arr[i]],btreemin[ind]);
			btree[ind][arr[i]] = i;
			bit.add(btreemin[ind]+1,-1);
			bit.add(1,1);
			loc>>=1;
		}
		while(head<q && qarr[head].r==i ){
			ans[qarr[head].t] = bit.query(qarr[head].l);
			head++;
		}
	}
	for(int i=0;i<q;i++){
		cout<<(x+y)*ans[i]+x<<"\n";
	}
	return 0;
}
