#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




struct bit{
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

struct BIT{
	vector<bit> arr;
	int _n;
	void init(int s){
		arr.resize(s+1);
		_n = s;
		for(int i=0;i<=_n;i++){
			arr[i].init(_n);
		}
	}
	void modify(int ind,int ind2,int v){
		while(ind<=_n){
			arr[ind].modify(ind2,v);
			ind+=(ind & -ind);
		}
	}
	int query(int ind,int ind2){
		int ans = 0;
		while(ind){
			ans+=arr[ind].query(ind2);
			ind-=(ind & -ind);
		}
		return ans;
	}

};
bool mp[1005][1005];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	BIT arr;
	arr.init(n);
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		for(int j=0;j<n;j++){
			if(s[j]=='*') arr.modify(i,j+1,1);
			mp[i][j+1] = s[j]=='*';
		}
	}
	while(q--){
		int t;cin>>t;
		if(t==1){
			int x,y;cin>>x>>y;
			if(mp[x][y]){
				arr.modify(x,y,-1);
				mp[x][y]=0;
			}else{
				arr.modify(x,y,1);
				mp[x][y]=1;
			}
		}else{
			int xa,ya,xb,yb;
			cin>>xa>>ya>>xb>>yb;
			xa--;ya--;
			cout<<arr.query(xb,yb)-arr.query(xa,yb)-arr.query(xb,ya)+arr.query(xa,ya)<<"\n";
		}
	}
	return 0;
}
