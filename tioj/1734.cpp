#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;
	while(cin>>n>>k){
		int ans[n+1];
		memset(ans,0,sizeof(ans));
		for(int i=0;i<min(n+1,k);i++){
			ans[i]= (1<<i);
		}
		for(int i=min(n+1,k);i<=n;i++){
			for(int j=i-1;j>=max(0,i-k);j--){
				ans[i]+=ans[j];
			}
		}
		cout<<ans[n]<<"\n";
	}


	return 0;
}
