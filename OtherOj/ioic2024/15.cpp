#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int dp[85][85][85][85];



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	string s,t;cin>>s>>t;
	for(int lens=1;lens<=n;lens++){
		for(int i=0;i+lens-1<n;i++){
			for(int lent=1;lent<=m;lent++){
				for(int j=0;j+lent-1<m;j++){
					if(lens==1 || lent==1){
						if(lens==lent) {
							dp[i][i][j][j]=(s[i]==t[j])?(1):(0);
						//	cout<<i<<"gg"<<j<<":"<<(s[i]==t[j])<<dp[i][i][j][j]<<"\n";
						}
						else{
							if(lens==1){
								dp[i][i+lens-1][j][j+lent-1]= max(dp[i][i+lens-1][j+1][j+lent-1],dp[i][i+lens-1][j][j+lent-2]);
							}else{
								dp[i][i+lens-1][j][j+lent-1]= max(dp[i+1][i+lens-1][j][j+lent-1],dp[i][i+lens-2][j][j+lent-1]);
							}
						}
					}else{
						if(s[i]==s[i+lens-1] && t[j]==s[i] && t[j]==t[j+lent-1]){
							dp[i][i+lens-1][j][j+lent-1] = max(2+dp[i+1][i+lens-2][j+1][j+lent-2],dp[i][i+lens-1][j][j+lent-1]);
						//	cout<<i<<i+lens-1<<" "<<j<<j+lent-1<<" "<<dp[i][i+lens-1][j][j+lent-1]<<'\n';
						}
						int sl = i;int sr = i+lens-1;
						int tl = j;int tr = j+lent-1;
						dp[sl][sr][tl][tr] = max(dp[sl][sr][tl][tr],dp[sl+1][sr][tl][tr]);
						dp[sl][sr][tl][tr] = max(dp[sl][sr][tl][tr],dp[sl][sr-1][tl][tr]);
						dp[sl][sr][tl][tr] = max(dp[sl][sr][tl][tr],dp[sl][sr][tl+1][tr]);
						dp[sl][sr][tl][tr] = max(dp[sl][sr][tl][tr],dp[sl][sr][tl][tr-1]);
					}
				}
			}
		}
	}
	/*
	for(int sl=0;sl<n;sl++){
		for(int sr=sl;sr<n;sr++){
			cout<<sl<<"-"<<sr<<":\n";
			for(int tl=0;tl<m;tl++){
				for(int tr=tl;tr<m;tr++){
					cout<<dp[sl][sr][tl][tr]<<" ";
				}
			cout<<"\n";
			}
			cout<<"\n\n";
		}
	}*/
	cout<<dp[0][n-1][0][m-1]<<"\n";
	return 0;
}
