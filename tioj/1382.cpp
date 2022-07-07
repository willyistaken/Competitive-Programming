#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct bit{
	vector<int> a;
	int size;
	void init(int _n){
		size = _n;
		a.resize(_n+1);
		for(int i=1;i<=size;i++){
			a[i] = ((i&-i));
		}
	}
	void remove(int ind){
		while(ind<=size){
			a[ind]-=1;
			ind+=(ind & -ind);
		}
	}
	int query(int ind){
		int sum=0;
		while(ind){
			sum+=a[ind];
			ind-=(ind & -ind);
		}
		return sum;
	}
	int search(int p,int q){
		int nowsize = query(size);	
		q%=nowsize;
		int want = (query(p)+q);
		want = (want>nowsize) ? want-nowsize:want;
		int l=0;int r=size;
		while(r-l>1){
			int mid = (l+r)/2;
			if(query(mid)>=want){
				r = mid;
			}else{
				l=mid;
			}
		}
		return r;
	}
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n){
	bit BIT;
	BIT.init(n);
	int cur=1;
	for(int i=0;i<n;i++){
		int k;cin>>k;
		k--;
		int	toberemove = BIT.search(cur,k);
		cout<<toberemove<<" ";
		cur = BIT.search(toberemove,1);
		BIT.remove(toberemove);
	}
	cout<<"\n";
	}	




	return 0;
}
