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
		string s;cin>>s;
		int sum = 0;
		for(int i=0;  i<n;i++){
			if(s[i]=='Q'){
				sum++;
			}else{
				sum--;
				sum = max(sum,0);
			}
		}
		if(sum) cout<<"No\n";
		else cout<<"Yes\n";
	}

	return 0;
}
