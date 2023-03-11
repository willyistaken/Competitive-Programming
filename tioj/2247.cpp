#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct T{
	int n;
	char l;
	char r;
};

string side[26] = {
	"aqwsz",
	"bghvn",
	"cdfxv",
	"dersfxc",
	"ewrsd",
	"frtdgcv",
	"gtyfhvb",
	"hyugjbn",
	"iuojk",
	"juihknm",
	"kiojlm",
	"lopk",
	"mjkn",
	"nhjbm",
	"oipkl",
	"pol",
	"qwa",
	"retdf",
	"sweadzx",
	"tryfg",
	"uyihj",
	"vfgcb",
	"wqeas",
	"xsdzc",
	"ytugh",
	"zasx"
};
int dis[26][26];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	string s;cin>>s;
	s = " "+s;
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++) dis[i][j]=1e5;
	}
	for(int i=0;i<26;i++) dis[i][i]=0;
	for(int i=0;i<26;i++){
		for(auto c : side[i]){
			dis[i][c-'a']=min(1,dis[i][c-'a']);
		}
	}
	for(int g=0;g<3;g++){
	for(int k=0;k<26;k++){
		for(int i=0;i<26;i++){
			for(int j=0;j<26;j++){
				dis[i][j]=  min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	}
	ll dp[n+1][26][26];
	for(int k=0;k<=n;k++){
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			dp[k][i][j]=1e12;
		}
	}
	}
	dp[0]['F'-'A']['J'-'A']=0;
	for(int k=0;k<n;k++){
		for(int i=0;i<26;i++){
			for(int j=0;j<26;j++){
				if(dp[k][i][j]>1e11) continue;
				dp[k+1][i][s[k+1]-'A'] = min(dp[k+1][i][s[k+1]-'A'],dp[k][i][j]+dis[j][s[k+1]-'A']);
				dp[k+1][s[k+1]-'A'][j] = min(dp[k+1][s[k+1]-'A'][j],dp[k][i][j]+dis[i][s[k+1]-'A']);
			}
		}
	}
	ll minn = 1e12;						
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			minn = min(minn,dp[n][i][j]);
		}
	}
	cout<<minn<<"\n";
	return 0;
}
