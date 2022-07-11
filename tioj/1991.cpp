#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	bool obs[m+1]={0};
	int placeh[n+1][m+1]={{0}};
	int placev[n+1][m+1]={{0}};
	memset(obs,0,sizeof(obs));
	memset(placev,0,sizeof(placev));
	memset(placeh,0,sizeof(placeh));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int temp;cin>>temp;
			if(temp){
				if(obs[j-1]) placeh[i][j]=1;
				if(obs[j]) placev[i][j]+=1;
			}
			obs[j]=temp;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			placev[i][j] += placev[i-1][j]+placev[i][j-1]-placev[i-1][j-1];
			placeh[i][j] += placeh[i-1][j]+placeh[i][j-1]-placeh[i-1][j-1];
		}
	}
	int q;cin>>q;
	while(q--){
		int r1,r2,c1,c2;cin>>r1>>c1>>r2>>c2;	
		int ans = placev[r2][c2]-placev[r2][c1-1]-placev[r1][c2]+placev[r1][c1-1];
		ans += placeh[r2][c2]-placeh[r2][c1]-placeh[r1-1][c2]+placeh[r1-1][c1];
		cout<<ans<<"\n";
	}
	return 0;
}
