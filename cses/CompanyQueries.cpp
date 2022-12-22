#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 2e5+5;
int f[N][25];


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;		
	for(int i=2;i<=n;i++){
		cin>>f[i][0];
	}
	for(int j = 1;j<25;j++){
		for(int i=2;i<=n;i++){
			f[i][j] = (f[f[i][j-1]][j-1]);
		}
	}
	while(m--){
		int x,k;cin>>x>>k;
		for(int i=0;i<25;i++){
			if((k>>i) & 1) {
				x= f[x][i];
			}
		}
		if(x) cout<<x<<"\n";
		else cout<<-1<<"\n";
	}
	return 0;
}
