#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
struct person{
	string name;
	vector<vector<int> > board;
	person(){ 
		board.resize(5);
		for(int i=0;i<5;i++) board[i].resize(5);
	}
};
bool balls[91];
bool bingo(vector<vector<int> > &board){
	vector<vector<bool> > yes(5,vector<bool>(5,0));	
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			yes[i][j] = balls[board[i][j]];
		}
	}
	bool y=0;
	for(int i=0;i<5;i++){
		bool k=1;
		for(int j=0;j<5;j++){
			k&=yes[i][j];
		}
		y|=k;
	}
	for(int i=0;i<5;i++){
		bool k=1;
		for(int j=0;j<5;j++){
			k&=yes[j][i];
		}
		y|=k;
	}
	bool k=1;
	for(int i=0;i<5;i++){
		k&=yes[i][i];
	}
	y|=k;	
	k=1;
	for(int i=0;i<5;i++){
		k&=yes[i][4-i];
	}
	y|=k;
	return y;
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;	
	vector<person> p(n);
	for(int i=0;i<n;i++){
		cin>>p[i].name;
		for(int j=0;j<5;j++){
			for(int k=0;k<5;k++) cin>>p[i].board[j][k];
		}
	}
	int m;cin>>m;
	for(int i=0;i<m;i++){
		int a;cin>>a;
		balls[a]=1;
	}
	vector<int> ans;
	for(int i=0;i<n;i++){
		if(bingo(p[i].board)) ans.push_back(i);
	}
	cout<<ans.size()<<"\n";
	for(auto i : ans){
		cout<<p[i].name<<"\n";
	}
	return 0;
}
