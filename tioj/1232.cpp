#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> number;

void putinnumbers(ll now,int n,int mask,int r){
	if(r==0) {
		number.push_back(now);
		return;
	}
	for(int i=0;i<n;i++){
		if(!(mask>>i & 1)){
			putinnumbers(now*10+i,n,mask+(1<<i),r-1);		
		}
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,r;cin>>n>>r;
	putinnumbers(0,n,0,r);
	if(n+r>number.size()) cout<<number[0]<<"\n";
	else cout<<number[number.size()-n-r]<<"\n";


	return 0;
}
