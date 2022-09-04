#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n,k,r,c;cin>>n>>k>>r>>c;
		int shift = k-((r+c)%k);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if((i+j+shift)%k==0) cout<<"X";
				else cout<<".";
			}
			cout<<"\n";
		}
	}

	return 0;
}
