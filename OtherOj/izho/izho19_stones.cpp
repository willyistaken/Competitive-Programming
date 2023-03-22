#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

bool arr[1005][1005];
 
void solve(){
	memset(arr,0,sizeof(arr));
	int n,m;cin>>n>>m;
	if(n>m){
		int k = m-(m/2)-1;
		int total = k*n/((n/2)+1);
		int p=0;
		for(int i=0;i<n;i++){
			for(int g=0;g<k;g++){
				arr[i][p]=1;
				p = (p+1)%total;
			}
		}
		cout<<n+total<<"\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j]) cout<<"-";
				else cout<<"+";
			}
			cout<<"\n";
		}
	}else{
		int k = n-(n/2)-1;
		int total = k*m/((m/2)+1);
		int p=0;
		for(int i=0;i<m;i++){
			for(int g=0;g<k;g++){
				arr[p][i]=1;
				p = (p+1)%total;
			}
		}
		cout<<m+total<<"\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j]) cout<<"+";
				else cout<<"-";
			}
			cout<<"\n";
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
