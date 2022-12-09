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
	}
	void change(int ind,int v){
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
	int size(){
	 	return query(s);
	}
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int k;cin>>k;
	bit s;
	s.init(n);
	for(int i=1;i<=n;i++){
		s.change(i,1);
	}
	int cur = 1;
	for(int i=0;i<n;i++){
		int g = k%s.size();
		if(cur+g>s.size()){
			cur = cur+g-s.size();
		}else{
			cur+=g;
		}
		int l = 0; int r = n;
		while(r-l>1){
			int mid = (l+r)/2;
			if(s.query(mid)>=cur) r = mid;
			else l = mid;
		}
		cout<<r<<" \n"[i==n-1];
		s.change(r,-1);
	}
	return 0;
}
