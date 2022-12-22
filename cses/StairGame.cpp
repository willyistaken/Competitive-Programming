#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int r = 0;
		int n;cin>>n;
		for(int i=0;i<n;i++){
			int a;cin>>a;
			if(i%2) r^=a;
		}
		if(r) cout<<"first\n";
		else cout<<"second\n";
	}
	

	return 0;
}
