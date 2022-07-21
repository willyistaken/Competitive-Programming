#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int cango[4];
		cin>>cango[0];
		for(int i=0;i<3;i++) cin>>cango[i+1];
		bool vis[4];
		memset(vis,0,sizeof(vis));
		int cur = 0 ;
		while(!vis[cur]){
			vis[cur]=1;
			cur = cango[cur];
		}
		bool flag=0;
		for(int i=0;i<4;i++){
			if(!vis[i]){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"NO\n";	
		}else{
			cout<<"YES\n";	
		}
	}

	return 0;
}
