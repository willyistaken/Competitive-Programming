#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	bool works[n+1];
	memset(works,0,sizeof(works));
	for(int i=0;i<n-1;i++){
		int k;cin>>k;
		works[k]=1;
	}
	for(int i=1;i<=n;i++){
		if(!works[i]){
			cout<<i<<"\n";
			return 0;
		}
	}
	return 0;
}
