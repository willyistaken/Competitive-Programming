#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	bool arr[n+2][m+2];
	pair<int,int> sp;
	pair<int,int> ep;
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		for(int j=1;j<=m;j++){
			arr[i][j] = (s[j-1]=='#');
			if(s[j-1]=='A') sp = {i,j};
			if(s[j-1]=='B') ep = {i,j};
		}
	}
	for(int i=0;i<n+2;i++){
		arr[i][0]=1;
		arr[i][m+1]=1;
	}
	for(int i=0;i<m+2;i++){
		arr[0][i]=1;
		arr[n+1][i]=1;
	}
	/*for(int i=0;i<n+2;i++){
		for(int j=0;j<m+2;j++) cout<<arr[i][j];
		cout<<endl;
	}*/
	arr[sp.first][sp.second] = 1;
	queue<pair<int,int> > q;
	q.push(sp);
	int fromdir[n+2][m+2] = {{0}};
	while(q.size()){
		pair<int,int> t = q.front();
		q.pop();
		if(t.first==ep.first && t.second==ep.second){
			cout<<"YES\n";
			char carr[5] = {'$','D','U','R','L'};
			pair<int,int> garr[5] = {{0,0},{-1,0},{1,0},{0,-1},{0,1}};
			int curx = t.first;int cury = t.second;
			stack<char> ack;
			while(fromdir[curx][cury]){
				int p = fromdir[curx][cury];
				ack.push(carr[p]);
				curx+=garr[p].first;
				cury+=garr[p].second;
			}
			cout<<ack.size()<<"\n";
			while(ack.size()){
				cout<<ack.top();
				ack.pop();
			}
			cout<<"\n";
			return 0;
		}
		if(!arr[t.first+1][t.second]){
			fromdir[t.first+1][t.second] = 1;
			arr[t.first+1][t.second]=1;
			q.push({t.first+1,t.second});
		}
		if(!arr[t.first-1][t.second]){
			fromdir[t.first-1][t.second] = 2;
			arr[t.first-1][t.second]=1;
			q.push({t.first-1,t.second});
		}
		if(!arr[t.first][t.second+1]){
			fromdir[t.first][t.second+1] = 3;
			arr[t.first][t.second+1]=1;
			q.push({t.first,t.second+1});
		}
		if(!arr[t.first][t.second-1]){
			fromdir[t.first][t.second-1] = 4;
			arr[t.first][t.second-1]=1;
			q.push({t.first,t.second-1});
		}
	}
	cout<<"NO\n";
	return 0;
}
