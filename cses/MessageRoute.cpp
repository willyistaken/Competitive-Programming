#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	int from[n];
	fill(from,from+n,-1);
	from[0]=0;
	vector<int> side[n];
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		a--;b--;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	queue<int> q;
	q.push(0);
	while(q.size()){
		int cur = q.front();
		q.pop();
		for(auto i : side[cur]){
			if(from[i]<0){
				from[i] = cur;
				q.push(i);
			}
		}
	}
	if(from[n-1]<0){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}else{
		stack<int> route;
		int cur = n-1;
		while(cur){
			route.push(cur);	
			cur = from[cur];
		}
		cout<<route.size()+1<<"\n";
		cout<<1<<" ";
		while(route.size()){
			cout<<route.top()+1<<" ";
			route.pop();
		}
		cout<<"\n";
	}	
	return 0;
}
