#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
 
int n,m;
int arr[100][100];
int cnt(){
	int ans = 0;
	for(int i=0;i<n;i++){
		int zcnt = 0;
		for(int j=0;j<m;j++){
			zcnt+=arr[i][j]==0;
		}
		if(zcnt>(m)/2) ans++;
	}
	for(int j=0;j<m;j++){
		int ocnt = 0;
		for(int i=0;i<n;i++){
			ocnt+=arr[i][j]==1;
		}
		if(ocnt>(n)/2) ans++;
	}
	return ans;
}
 
void solve(){
	cin>>n>>m;
	pair<int,int> maxn ={0,0};
	for(int mask=0;mask<(1<<(n*m));mask++){
		for(int i=0;i<n*m;i++){
			arr[i/m][i%m]=(mask>>i)&1;
		}
		maxn = max(make_pair(cnt(),mask),maxn);
	}
	cout<<maxn.first<<"\n";
	for(int i=0;i<n*m;i++){
		arr[i/m][i%m]=(maxn.second>>i)&1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<((arr[i][j])?('-'):('+'));
		}
		cout<<"\n";
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

