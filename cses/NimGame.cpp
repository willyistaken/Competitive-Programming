#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int s = 0;
		for(int i=0;i<n;i++){
			int a;cin>>a;
			s^=a;
		}
		if(s) cout<<"first\n";
		else cout<<"second\n";
	}

	return 0;
}
