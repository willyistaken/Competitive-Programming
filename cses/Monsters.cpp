#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int arr[1005][1005];

int dx[7] = {0,0,0,1,-1,0,0};
int dy[7] = {0,0,0,0,0,1,-1};
char dir[7] = {' ',' ',' ','D','U','R','L'};
stack<char> ans;
void backtrack(int x,int y){
	ans.push(dir[arr[x][y]]);	
	if(ans.top()==' '){
		ans.pop();
	}else{
		backtrack(x-dx[arr[x][y]],y-dy[arr[x][y]]);
	}
}

bool takestep(queue<pair<int,int> > &a,bool type){
	queue<pair<int,int> > next;
	while(a.size()){
		auto t = a.front();
		a.pop();
		for(int i=3;i<7;i++){
			if(type && arr[t.first+dx[i]][t.second+dy[i]]==2){
				backtrack(t.first,t.second);
				return 1;
			}
			if(!arr[t.first+dx[i]][t.second+dy[i]]){
				arr[t.first+dx[i]][t.second+dy[i]] = (type)?(i):(1);
				next.push({t.first+dx[i],t.second+dy[i]});
			}
		}
	}
	a = next;
	return 0;
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;	
	for(int i=0;i<n+2;i++){
		arr[i][0]=2;
		arr[i][m+1]=2;
	}
	for(int i=0;i<m+2;i++){
		arr[0][i]=2;
		arr[n+1][i]=2;
	}
	queue<pair<int,int> > hero;	
	queue<pair<int,int> > monster;	
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		for(int j=1;j<=m;j++){
			arr[i][j] = !(s[j-1]=='.');
			if(s[j-1]=='A') hero.push({i,j});
			if(s[j-1]=='M') monster.push({i,j});
		}
	}
	while(hero.size()){
		takestep(monster,0);
		if(takestep(hero,1)){
			cout<<"YES\n";
			cout<<ans.size()<<"\n";
		/*	for(int i=0;i<n+2;i++){
				for(int j=0;j<m+2;j++){
					cout<<arr[i][j];
				}
				cout<<"\n";
			}*/
			while(ans.size()){
				cout<<ans.top();
				ans.pop();
			}
			cout<<"\n";
			return 0;
		}
	}
	cout<<"NO\n";

	return 0;
}
