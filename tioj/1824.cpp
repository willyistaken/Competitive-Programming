#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int rem[10]={1,3,2,6,4,5,1,3,2,6};
int rrem[10]={1,5,4,6,2,3,1,5,4,6};
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;cin>>s;
	int nowre=0;
	int which=0;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]=='?') which=s.size()-i-1;
		else{
			nowre+= ((s[i]-'0')*rem[s.size()-i-1])%7;
			nowre%=7;
		}
	}
	int ans = 7-nowre;
	ans*=rrem[which];
	ans%=7;
	if(ans<=2){
		cout<<s.substr(0,s.size()-which-1)<<ans<<s.substr(s.size()-which,which+1)<<"\n";
		cout<<s.substr(0,s.size()-which-1)<<ans+7<<s.substr(s.size()-which,which+1)<<"\n";
	}else{
		cout<<s.substr(0,s.size()-which-1)<<ans<<s.substr(s.size()-which,which+1)<<"\n";
	}
	return 0;
}
