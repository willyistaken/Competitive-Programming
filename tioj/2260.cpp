#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int q;cin>>q;
	for(int i=0;i<q;i++){	
		int v,u,x;cin>>v>>u>>x;
		if(v!=u) {
		cout<<-1<<endl;
		continue;
		}
		cout<<1<<endl;
	}
	return 0;
}
