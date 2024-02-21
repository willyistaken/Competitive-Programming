#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct BIT{
	vector<int> arr;
	int n;
	void init(int _n){
		n = _n;
		arr.resize(n+1);
	}
	void add(int ind,int v){
		ind+=1;
		while(ind<=n){
			arr[ind]+=v;
			ind+=(ind&-ind);
		}
	}
	int query(int ind){
		ind+=1;
		int s = 0;
		while(ind){
			s+=arr[ind];
			ind-=(ind&-ind);
		}
		return s;
	}
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	vector<string> a(n+1);
	vector<string> b(m+1);
	BIT acnt;
	BIT bcnt;
	acnt.init(n+1);
	bcnt.init(m+1);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	a[n] = "{";
	b[m] = "{";
	vector<pair<int,int> > aran(n);
	vector<pair<int,int> > bran(m);
	{
	int l = m;int r = m;
	for(int i=n-1;i>=0;i--){
		while(l>=0 && b[l]>a[i])	{
			l--;
		}
		while(r>l && b[r][0]>a[i][0]+1){
			r--;
		}
		aran[i] = {l,r};
	}
	l = n;r=n;
	for(int i=m-1;i>=0;i--){
		while(l>=0 && a[l]>b[i]){
			l--;
		}
		while(r>l && a[r][0]>b[i][0]+1){
			r--;	
		}
		bran[i] = {l,r};
	}
	}
	acnt.add(n,1);
	bcnt.add(m,1);
	int head1 = n-1;	
	int head2 = m-1;
	for(int i=0;i<n+m;i++){
		if(head1<0)	{
			int l = bran[head2].first;
			int r = bran[head2].second;
			if(acnt.query(r)-acnt.query(l)<(r-l)) bcnt.add(head2,1);
			head2--;
		}else if(head2<0){
			int l = aran[head1].first;
			int r = aran[head1].second;
			if(bcnt.query(r)-bcnt.query(l)<(r-l)) acnt.add(head1,1);
			head1--;
		}else{
			if(a[head1]>b[head2]){
			int l = aran[head1].first;
			int r = aran[head1].second;
			if(bcnt.query(r)-bcnt.query(l)<(r-l)) acnt.add(head1,1);
			head1--;
				
			}else{
			int l = bran[head2].first;
			int r = bran[head2].second;
			if(acnt.query(r)-acnt.query(l)<(r-l)) bcnt.add(head2,1);
			head2--;
			}
		}
	}
	/*
	for(int i=0;i<=n;i++){
		cout<<acnt.query(i)-acnt.query(i-1)<<" ";
	}
	cout<<"\n";
	for(int i=0;i<=m;i++){
		cout<<bcnt.query(i)-bcnt.query(i-1)<<" ";
	}
	cout<<"\n";
	*/
	if(acnt.query(0)==0) cout<<"Leona\n";
	else cout<<"Zoe\n";
	return 0;
}
