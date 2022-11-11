#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	vector<int> p(n+1,0);
	vector<int> b(n+1,0);
	int k  = sqrt(n);
	vector<int> pk(n+1,0);
	for(int i=1;i<=n;i++) pk[i] = i;
	for(int i=1;i<=n;i++) {
		cin>>p[i];
		b[p[i]] = i;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<k;j++){
			pk[i] = p[pk[i]];
		}
	}
	while(q--){
		int ty;cin>>ty;	
		if(ty==1){
			int x,y;cin>>x>>y;	
			swap(b[p[x]],b[p[y]]);
			swap(p[x],p[y]);
			pk[x] = x;
			for(int i=0;i<k;i++){
				pk[x] = p[pk[x]];
			}
			pk[y] = y;
			for(int i=0;i<k;i++){
				pk[y] = p[pk[y]];
			}
			int cur = x;
			int curk = pk[x];
			for(int i=0;i<=k;i++){
				cur = b[cur];	
				curk = b[curk];
				pk[cur] = curk;
			}
			cur=  y;
			curk = pk[y];
			for(int i=0;i<=k;i++){
				cur = b[cur];
				curk = b[curk];
				pk[cur] = curk;
			}
		}else{
			int c,n;cin>>c>>n;
			while(n>=k){
				c = pk[c];
				n-=k;
			}
			for(int i=0;i<n;i++){
				c = p[c];
			}
			cout<<c<<"\n";
		}
		/*
		cout<<"p:";
		for(int i=1;i<=n;i++) cout<<p[i]<<" ";
		cout<<"\n";
		cout<<"b:";
		for(int i=1;i<=n;i++) cout<<b[i]<<" ";
		cout<<"\n";
		cout<<"pk:";
		for(int i=1;i<=n;i++) cout<<pk[i]<<" ";
		cout<<"\n";
		*/
	}
	return 0;
}
