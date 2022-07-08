#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5+5;
bitset<MAXN> vis;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		vis.reset();
		int n;cin>>n;
		vector<int> arr;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				for(int j=0;i*(1<<j)<=n;j++){
					vis[i*(1<<j)]=1;
					arr.push_back(i*(1<<j));
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				arr.push_back(i);
			}
		}
		cout<<2<<"\n";
		for(auto i : arr){
			cout<<i<<" ";
		}
		cout<<"\n";
	}

	return 0;
}
