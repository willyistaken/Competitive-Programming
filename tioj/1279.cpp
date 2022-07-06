#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct stuff{
	int v=0;
	int x=0;
	int y=0;
};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	int value[n][m];
	bool circle[n][m];
	vector<stuff> arr;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>value[i][j];
			stuff g;
			g.v = value[i][j];
			g.x =i;
			g.y=j;
			arr.push_back(g);
			circle[i][j]=0;
		}
	}
	sort(arr.begin(),arr.end(),[](const stuff &a,const stuff &b){return a.v>b.v;});
	ll sum=0;
	for(auto s:arr){
		sum+=s.v;
		for(int i=0;i<4;i++){
			if(s.x+dx[i]>=0 && s.x+dx[i]<n && s.y+dy[i]>=0 && s.y+dy[i]<m ){
				if(circle[s.x+dx[i]][s.y+dy[i]]){
					sum+=value[s.x+dx[i]][s.y+dy[i]];
				}
			}
		}
		circle[s.x][s.y]=1;
	}
	cout<<sum<<"\n";




	return 0;
}
