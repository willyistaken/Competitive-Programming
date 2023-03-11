#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


char arr[1005][1005];
int n,m;
int dx[4]={0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool inbound(int x,int y){
	return (x>=0 && x<n && y>=0 && y<m);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;	
	for(int i=0;i<n;i++){
		string s;cin>>s;
		for(int j=0;j<m;j++){
			arr[i][j] = s[j];
		}
	}
	queue<pair<int,int> > bq;
	queue<pair<int,int> > tq;
	int cnt = 0;
	if(arr[n-1][m-1]=='B') bq.push({n-1,m-1});
	else tq.push({n-1,m-1});
	
	while(tq.size() || bq.size()){
		if(tq.size()) cnt++;
		while(tq.size()){
			auto p = tq.front();
			int x = p.first;
			int y = p.second;
			tq.pop();
			for(int i=0;i<4;i++){
				if(inbound(x+dx[i],y+dy[i])){
					if(arr[x+dx[i]][y+dy[i]]=='B'){
						bq.push({x+dx[i],y+dy[i]});
					}
					if(arr[x+dx[i]][y+dy[i]]=='T'){
						tq.push({x+dx[i],y+dy[i]});
					}
					arr[x+dx[i]][y+dy[i]] = '*';
				}
			}
		}
		if(bq.size()) cnt++;
		while(bq.size()){
			auto p = bq.front();
			int x = p.first;
			int y = p.second;
			bq.pop();
			for(int i=0;i<4;i++){
				if(inbound(x+dx[i],y+dy[i])){
					if(arr[x+dx[i]][y+dy[i]]=='B'){
						bq.push({x+dx[i],y+dy[i]});
					}
					if(arr[x+dx[i]][y+dy[i]]=='T'){
						tq.push({x+dx[i],y+dy[i]});
					}
					arr[x+dx[i]][y+dy[i]] = '*';
				}
			}
		}
	}
	cout<<cnt<<"\n";


	return 0;
}
