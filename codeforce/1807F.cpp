#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int dx[4] = {1,-1};
int dy[4] = {1,-1};
map<string,pair<int,int>> mp = {{"DR",{0,0}},{"DL",{0,1}},{"UR",{1,0}},{"UL",{1,1}}};
void solve(){
	int n,m,sx,sy,ex,ey;
	cin>>n>>m>>sx>>sy>>ex>>ey;
	string d;cin>>d;
	int xd = mp[d].first;
	int yd = mp[d].second;
	int cnt = 0;
	for(int i=0;i<4*n*m;i++){
		if(sx==ex && sy==ey){
			cout<<cnt<<"\n";
			return ;
		}
		bool bounce = 0;
		if(sx<=1 && xd==1) {
			xd^=1;			
			if(!bounce) cnt++;
			bounce = 1;
		}
		if(sy<=1 && yd==1){
			yd^=1;
			if(!bounce) cnt++;
			bounce = 1;
		}
		if(sx>=n && xd==0){
			xd^=1;
			if(!bounce) cnt++;
			bounce = 1;
		}
		if(sy>=m && yd==0){
			yd^=1;
			if(!bounce) cnt++;
			bounce = 1;
		}
		sx+=dx[xd];
		sy+=dy[yd];
	}
	cout<<-1<<"\n";
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
