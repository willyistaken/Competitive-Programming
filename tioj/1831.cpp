#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,type;cin>>n>>m>>type;
	if(type){
		set<int> side[n+1];
		for(int i=0;i<m;i++){
			int a,b;
			string g;cin>>a>>g>>b;
			if(g=="->"){
				side[a].insert(b);	
			}else{
				side[b].insert(a);	
			}
		}
		for(int i=1;i<=n;i++){
			cout<<i<<" ->";
			if(side[i].empty()) cout<<" 0\n";
			else{
				for(auto g:side[i]) cout<<" "<<g;
				cout<<"\n";
			}
		}
	}else{
		int arr[n+1][n+1];
		memset(arr,0,sizeof(arr));
		for(int i=0;i<m;i++){
			int a,b;
			string g;cin>>a>>g>>b;
			if(g=="->"){
				arr[a][b]=1;	
			}else{
				arr[b][a]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<arr[i][j]<<" \n"[j==n];
			}
		}
		
	}
	return 0;
}
