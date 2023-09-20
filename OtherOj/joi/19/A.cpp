#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int h,w;cin>>h>>w;
	vector<string> grid(h);
	for(int i=0;i<h;i++){
		cin>>grid[i];
	}
	vector<vector<int> > sumO(h+1,vector<int>(w+1,0));
	vector<vector<int> > sumI(h+1,vector<int>(w+1,0));
	ll ans = 0;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			sumO[i][j] = sumO[i][j-1]+(grid[i-1][j-1]=='O');
			sumI[i][j] = sumI[i-1][j]+(grid[i-1][j-1]=='I');
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(grid[i-1][j-1]=='J')	{
				ans+=1LL*(sumO[i][w]-sumO[i][j])*(sumI[h][j]-sumI[i][j]);
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
