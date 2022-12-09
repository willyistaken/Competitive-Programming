#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int MOD;
int side[1<<15][2];
bool vis[1<<15];
stack<int> stk;
void dfs(int v){
	for(int i=0;i<2;i++){
		if(side[v][i]>=0){
			int a = side[v][i];
			side[v][i]=-1;
			dfs(a);
		}
	}
	stk.push(v);
}
int n;
void prt(int v){
	for(int i=n-1;i>=0;i--) cout<<((v>>i)&1);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	if(n==1){
		cout<<"01\n";
		return 0;
	}
	n--;
	MOD = (1<<n);
	for(int i=0;i<(1<<n);i++){
		side[i][0] = (2*i)%MOD;
		side[i][1] = (2*i+1)%MOD;
		//cout<<side[i][0]<<" "<<side[i][1]<<"\n";
	}
	dfs(0);
	vector<int> tour;
	while(stk.size()){
		tour.push_back(stk.top());
		stk.pop();
	}
	prt(tour[0]);
	for(int i=0;i<tour.size();i++){
		if(i+1<tour.size()) cout<<(tour[i+1]&1);
	}
	return 0;
}
