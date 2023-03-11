#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


void solve(){
	int n;cin>>n;
	string s;cin>>s;
	int cnt = 0;
	for(auto c :s) cnt+=(c=='1');
	if(cnt%2){cout<<-1<<"\n";return ;}
	if(cnt!=2){cout<<cnt/2<<"\n";}
	else{
		if(n==2){
			cout<<-1<<"\n";
			return ;
		}
		bool next = 0;
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				if(s[i+1]=='1') next=1;
				break;
			}
		}
		if(!next){
			cout<<1<<"\n";
			return ;
		}

		if(n>=5){
			cout<<2<<"\n";
			return ;
		}
		if(n==3){
			cout<<-1<<"\n";
			return ;
		}
		if(n==4){
			if(s=="0110") cout<<3<<"\n";
			else cout<<2<<"\n";
		}
	}
	
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
