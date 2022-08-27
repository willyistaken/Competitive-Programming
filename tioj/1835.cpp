#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	cin.ignore();
	while(t--){
		string a,b;
		getline(cin,a,'\n');
		getline(cin,b,'\n');
		int n = a.size();int m = b.size();
		a+=" ";b+=" ";
		reverse(a.begin(),a.end());reverse(b.begin(),b.end());
		short dp[n+1][m+1];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1]+1;
				else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
		if(dp[n][m]==0){
			cout<<"妹萌えこそ正義なのさ！\n";
			continue;
		}
		short la[n+1][127]={{0}};
		short lb[m+1][127]={{0}};
		for(int i=1;i<=n;i++){
			for(int c=33;c<127;c++){
				la[i][c] = (a[i]==(char)c?i:la[i-1][c]);
			}
		}

		for(int i=1;i<=m;i++){
			for(int c=33;c<127;c++){
				lb[i][c] = (b[i]==(char)c?i:lb[i-1][c]);
			}
		}
		int i = n;int j = m;
		for(int k=0;k<dp[n][m];k++){
			for(int c=33;c<127;c++){
				if(la[i][c]>0 && lb[j][c]>0 && dp[la[i][c]-1][lb[j][c]-1]+1==dp[i][j]){
					cout<<(char)c;
					i = la[i][c]-1;
					j = lb[j][c]-1;
					break;
				}
			}
		}
		cout<<"\n";
	}
	return 0;
}
