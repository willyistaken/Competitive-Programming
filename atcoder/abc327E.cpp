#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define double long double
//#define double long double
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 5005;
double dp[N][N];
int P[N];

double mysqrt(int k){
	double r = k;
	for(int i=0;i<1000;i++){
		r = 0.5*(r+(k/r));	
	}
	return r;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;	
	double nn = 0.9;
	for(int i=0;i<=n;i++){
		for(int k=0;k<=n;k++) dp[i][k]=-1e18;
	}
	for(int i=1;i<=n;i++) cin>>P[i];
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			dp[i][k] = max(dp[i-1][k],(nn*dp[i-1][k-1])+P[i]);
		}
	}
	double g = 1200;
	double maxn = -1e18;
	double bottom=0;
	for(int k=1;k<=n;k++){
		bottom=nn*bottom+1;
		//if(k>1000) bottom=2;
		double minux = (g/sqrtl(k));
		maxn = max((dp[n][k]/bottom)-minux,maxn);
	}
	cout<<fixed<<setprecision(15)<<maxn<<"\n";
	return 0;
}
