#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n,m;
struct BIT{
	vector<int> arr;
	int n;
	void init(int s){
		n = s;
		arr.resize(n+1);
	}

	void add(int i,int x){
		while(i<=n){
			arr[i]+=x;
			i+=(i&-i);
		}
	}
	int query(int i){
		int sum = 0;
		while(i){
			sum+=arr[i];
			i-=(i&-i);
		}
		return sum;
	}
} bit;
int S;
vector<vector<int> > B;

vector<pair<int,int> > q;

vector<int> ans;

void do_things(int l,int r){
	for(int i=l;i<=r;i++){
		for(auto k : B[i]){
			bit.add(k,1);
		}
	}
	S = r;
}

void split(vector<int> &arr,vector<int> &left,vector<int> &right){
	for(auto i : arr){
		int p = q[i].first;
		int k = q[i].second;
		int l = max(1,p-S);
		int r = min(n,p+S);
		int cnt  = bit.query(r)-bit.query(l-1);
	//	cout<<i<<" "<<S<<" "<<cnt<<"\n";
		if(cnt>=k) left.push_back(i);
		else right.push_back(i);
	}
	vector<int>().swap(arr);
}


void undo_things(int l,int r){
	for(int i=r;i>=l;i--){
		for(auto k : B[i]){
			bit.add(k,-1);
		}
	}
	S = l-1;
}

void total_bs(int l,int r,vector<int> &arr){
	if(arr.empty()) return ;
	if(r==l){
		for(auto k : arr) ans[k]=r;
		return ;
	}
	int mid = (l+r)/2;
	do_things(l,mid);
	vector<int> left,right;
	split(arr,left,right);
	total_bs(mid+1,r,right);
	undo_things(l,mid);
	total_bs(l,mid,left);
}


vector<int> arr;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;	
	bit.init(n);
	B.resize(n+1);
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		B[k].push_back(i);
	}
	q.resize(m);
	arr.resize(m);
	ans.resize(m);
	for(int i=0;i<m;i++){
		cin>>q[i].first>>q[i].second;
		q[i].first++;
	}
	for(int i=0;i<m;i++){
		arr[i]=i;
	}
	total_bs(0,n,arr);
	for(int i=0;i<m;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}
