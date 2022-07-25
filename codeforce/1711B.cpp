#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		pair<int,int> unhappy[n];
		for(int i=0;i<n;i++){
			cin>>unhappy[i].first;
			unhappy[i].second=i;
		}
		if(m%2==0){
			cout<<0<<"\n";
			continue;
		}
		int ind[n]={0};
		for(int i=0;i<m;i++){
			int x,y;cin>>x>>y;
			x--;y--;
			ind[x]+=1;
			ind[y]+=1;
		}
		sort(unhappy,unhappy+n);
		bool flag=0;
		for(int i=0;i<n;i++){
			if(ind[unhappy[i].second]%2){
				cout<<unhappy[i].first<<"\n";
				break;
			}
		}
	}

	return 0;
}
