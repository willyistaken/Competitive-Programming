#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		bool col[10]={0},row[10]={0};
		while(m--){
			int xi,yi;cin>>xi>>yi;
			col[xi]=1;row[yi]=1;
		}
		bool flag=0;
		for(int i=1;i<=n;i++){
			if(!col[i]) {
				flag=1;
				cout<<"YES\n";
				break;
			}
			if(!row[i]){
				flag=1;
				cout<<"YES\n";
				break;
			}
		}
		if(!flag) cout<<"NO\n";
	}

	return 0;
}
