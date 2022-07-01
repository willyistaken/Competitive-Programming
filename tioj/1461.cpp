#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	while(cin>>n>>m && (n || m)){
		string s ="";
		for(int i=0;i<n;i++){
			string p;cin>>p;
			s+=p;
		}
		for(int j=0;j<m;j++){
			int k;cin>>k;
			k--;
			cout<<(s[k]);
		}
		cout<<"\n";
	}

	return 0;
}
