#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	ll sum[n+1][n+1] = {{0}};
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		for(int j=1;j<=n;j++){
			if(s[j-1]=='*'){
				sum[i][j]++;
			}
			sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		}
	}
	while(q--){
		int xa,ya,xb,yb;cin>>xa>>ya>>xb>>yb;
		xa--;ya--;
		cout<<abs(sum[xb][yb]-sum[xb][ya]-sum[xa][yb]+sum[xa][ya])<<"\n";
	}
	return 0;
}
