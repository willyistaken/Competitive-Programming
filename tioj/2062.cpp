#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::


vector<int> choose;
vector<vector<int> > side;

bool dfs(int r){
	bool flag=1;
	for(auto i : side[r]){
		if(!choose[i]){
			choose[i] = 3-choose[r];
			flag &= dfs(i);
		}else{
			if(choose[i]==choose[r]) return false;
		}
	}
	return flag;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	side.resize(n);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		a--;b--;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	choose.resize(n);	
	for(int i=0;i<n;i++){
		if(!choose[i]){
			choose[i]=1;
			if(!dfs(i)){
				cout<<-1<<"\n";
				return 0;
			}
		}
	}
	int ssize=0;int tsize=0;
	for(int i=0;i<n;i++){
		if(choose[i]==1) ssize++;
		if(choose[i]==2) tsize++;
	}
	cout<<ssize<<" "<<tsize<<"\n";
	for(int i=0;i<n;i++){
		if(choose[i]==1) cout<<i+1<<" ";
	}
	cout<<"\n";
	for(int i=0;i<n;i++){
		if(choose[i]==2) cout<<i+1<<" ";
	}
	cout<<"\n";
	return 0;
}
