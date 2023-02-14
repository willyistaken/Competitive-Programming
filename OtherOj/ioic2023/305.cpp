#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;	
	string s;cin>>s;
	ll ans = 0;
	for(int i=0;i<n;i++){
		int sum = 0;
		int cnt = 0;
		for(int j=i;j<n;j++){
			if(s[j]=='(') cnt++;
			else{
				if(cnt) sum+=2;
				cnt = max(0,cnt-1);
			}
			ans+=sum;
		}
	}
	cout<<ans<<"\n";

	return 0;
}
