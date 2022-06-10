#include "lib1227.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;


struct bit{
	vector<ll> arr;
	void change(int ind,ll v){
		while(ind<=arr.size()){
			arr[ind]+=v;
			ind += (ind & -ind);
		}
	}
	ll mquery(int ind){
		ll sum=0;
		while(ind){
			sum+=arr[ind];
			ind -= (ind & -ind);
		}
		return sum;
	}
};
bit DE;
bit DO;
void init(int n, long long d[]) {
	N = n;
	for(int i=0;i<=n;i++){
		(DE.arr).push_back(0);	
		(DO.arr).push_back(0);	
	}
	DO.change(1,d[0]);
	DE.change(2,d[1]);
	for(int i=3;i<=n;i++){
		if(i%2) DO.change(i,d[i-1]-d[i-3]);		
		else DE.change(i,d[i-1]-d[i-3]);
	}
}

void change(int a, int b, long long k) {
	a+=1;
	b+=1;
	DO.change(a,-k);
	DE.change(a,k);
	if(b<N){
		DO.change(b+1,k);
		DE.change(b+1,-k);
	}
}

long long query(int c) {
	c+=1;
	if(c%2){
		return DE.mquery(c)+1;	
	}else{
		return DO.mquery(c)+1;	
	}
}
/*
int main(){
	int n,m,q;cin>>n>>m>>q;
	long long d[n];
	for(int i=0;i<n;i++) cin>>d[i];
	init(n,d);
	for(int i=0;i<m;i++){
		int a,b;
		ll k;
		cin>>a>>b>>k;
		change(a,b,k);
	}
	for(int j=0;j<q;j++){
		int c;
		cin>>c;
		cout<<query(c)<<endl;
	}

}
*/

