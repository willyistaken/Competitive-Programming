#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct BIT{
	vector<ll> arr;
	int n;
	void init(int _n){
		n = _n;
		arr.resize(n+1);
	}
	void add(int ind,int v){
		while(ind<=n){
			arr[ind]+=v;
			ind+=(ind&-ind);
		}
	}
	ll query(int ind){
		ll sum = 0;	
		while(ind){
			sum+=arr[ind];
			ind-=(ind&-ind);
		}
		return sum;
	}
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	vector<int> arr1;
	vector<int> arr2;
	vector<int> ogarr(n,0);
	vector<int> type(n,0);
	map<int,int> s;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		ogarr[i]=a;
		if(s[a]>0){
			type[i]=2;
			arr2.push_back(a);
		}
		s[a]++;
	}
	for(int i=0;i<n;i++){
		if(s[ogarr[i]]>=2){
			type[i]=1;
			arr1.push_back(ogarr[i]);
		}
		s[ogarr[i]]--;
	}
	int cnt = arr1.size();
	ll ans = 0;
	int front = 1;
	int back = n-cnt+1;
	int mid = cnt+1;
	vector<int> allorder(n);
	for(int i=0;i<n;i++){
		if(type[i]==0)	allorder[i] = mid++;
		if(type[i]==1)	allorder[i] = front++;
		if(type[i]==2)	allorder[i] = back++;
	}
	BIT bit2;
	bit2.init(n);
	for(int i=n-1;i>=0;i--)	{
		ans+=bit2.query(allorder[i]);
		bit2.add(allorder[i],1);
	}

	map<int,int> reorder;
	for(int i=0;i<cnt;i++){
		reorder[arr1[i]]=i+1;
	}
	for(int i=0;i<cnt;i++){
		arr2[i] = reorder[arr2[i]];
	}
	BIT bit;
	bit.init(cnt);
	for(int i=cnt-1;i>=0;i--)	{
		ans+=bit.query(arr2[i]);
		bit.add(arr2[i],1);
	}
	cout<<ans<<"\n";
	return 0;
}
