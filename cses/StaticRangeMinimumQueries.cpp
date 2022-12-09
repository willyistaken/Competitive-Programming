#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	int minn[n][25];
	for(int i=0;i<n;i++){
		for(int j=0;j<25;j++) minn[i][j]=1e9;
	}
	for(int i=0;i<n;i++) cin>>minn[i][0];
	for(int j=1;j<25;j++){
		for(int i=0;i+(1<<(j-1))<n;i++){
			minn[i][j] = min(minn[i][j-1],minn[i+(1<<(j-1))][j-1]);
		}
	}
	while(q--){
		int a,b;cin>>a>>b;
		a--;b--;
		int p = __lg(b-a+1);
		cout<<min(minn[a][p],minn[b-(1<<p)+1][p])<<"\n";
	}
	

	return 0;
}
