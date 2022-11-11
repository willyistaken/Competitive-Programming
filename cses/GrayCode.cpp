#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n;
bool vis[1<<16];
void print(int k){
	for(int i=n-1;i>=0;i--){
		cout<<((k>>i)&1);
	}
	cout<<"\n";
}
void dfs(int k){
	if(vis[k]) return;
	print(k);
	vis[k]=1;
	for(int i=0;i<n;i++){
		dfs(k^(1<<i));
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;	
	dfs(0);
	return 0;
}
