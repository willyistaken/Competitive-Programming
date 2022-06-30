#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct sd{
	string s;
	int d;
};
int nf[4]={0};
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void nextfour(int n){
	int x = n/3;
	int y = n%3;
	for(int i=0;i<4;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx>=0 && nx<3 && ny>=0 && ny<3){
			nf[i]=((nx*3)+ny);
		}else{
			nf[i]=-1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	unordered_map<string,bool> vis;
	string start;
	for(int i=0;i<9;i++){
		char a;cin>>a;
		start.push_back(a);
	}
	string end;
	for(int i=0;i<9;i++){
		char a;cin>>a;
		end.push_back(a);
	}
	queue<sd> bfs;
	bfs.push({start,0});
	vis.insert({start,1});
	while(!bfs.empty()){
		sd temp = bfs.front();
		bfs.pop();
		int zpos=0;
		for(int i=0;i<9;i++){
			if(temp.s[i]=='0')	{zpos=i;break;}
		}
		if(temp.s==end){
			cout<<temp.d<<"\n";
			return 0;
		}
		nextfour(zpos);
		for(int i=0;i<4;i++){
			string ns = temp.s;
			if(nf[i]>=0){
				swap(ns[zpos],ns[nf[i]]);
				if(!vis.count(ns)){
					vis.insert({ns,1});
					bfs.push({ns,temp.d+1});
				}
			}
		}
	}
	return 0;
}
