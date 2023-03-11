#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


double p[5005][5005];

int mod(int k,int m){
	k%=m;
	if(k<0) k+=m;
	return k;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			double pow = 0.5;
			if(i==1){
				p[i][j]=1;			
			}else{
				for(int k=0;k<min(n,32);k++){
					if(k!=j) p[i][j] += pow*p[i-1][mod(j-k-1,i-1)];
					pow*=0.5;
				}
				p[i][j]/=(1.0-(2*pow));
			}
		}
	}
	cout<<p[n][m-1]<<"\n";
	return 0;
}
