#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


void solve(){
	int n,x;cin>>n>>x;
	vector<int> degree(n+1);
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		degree[a]++;
		degree[b]++;
	}
	if(degree[x]<=1){
		cout<<"Ayush\n";
	}else{
		if(n%2){
			cout<<"Ashish\n";
		}else{
			cout<<"Ayush\n";	
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
