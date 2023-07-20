#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;cin>>s;
	int n = s.size();
	n--;
	for(int i=0;i<(1<<n);i++){
		bool works = 1;
		for(int j=0;j<(n);j++){
			if(((i>>j)&1)&&((i>>(j+1))&1)) {
				works=0;
				break;
			}
			if((i>>j)&1){
			if(s[j]!='S' || s[j+1]!='S'){
				works=0;
				break;
			}
			}
		}
		if(!works) continue;
		string ans = "";
		for(int j=0;j<=n;j++){
			if((i>>j)&1){
				j++;
				ans.push_back('B');
				continue;
			}
			if(j<=s.size()) ans.push_back((char)(s[j]+32));
		}
		cout<<ans<<"\n";
		//for(int j=0;j<n;j++) cout<<((i>>j)&1);
		//cout<<"\n";
			
	}

	return 0;
}
