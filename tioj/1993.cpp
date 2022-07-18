#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


bitset<100005> dp;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//bitset optimization
	int t;cin>>t;
	while(t--){
		int n,H;cin>>n>>H;
		dp.reset();
		dp[0]=1;
		for(int i=1;i<=n;i++){
			int a,b,c;cin>>a>>b>>c;
				dp =(dp<<a)|(dp<<b)|(dp<<c); 
		}
		bool flag=0;
		for(int i=H;i>=0;i--){
			if(dp[i]){
				cout<<i<<"\n";
				i=-1;flag=1;
			}
		}
		if(!flag) cout<<"no solution\n";
	}

	return 0;
}
