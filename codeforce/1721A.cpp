#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		bool cnt[26]={0};
		string t,b;cin>>t>>b;
		t+=b;
		int pixelcnt=0;
		for(int i=0;i<4;i++){
			if(!cnt[t[i]-'a']){
				pixelcnt++;
				cnt[t[i]-'a']=1;
			}
		}
		cout<<pixelcnt-1<<"\n";

	}

	return 0;
}
