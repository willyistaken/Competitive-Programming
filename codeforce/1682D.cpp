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
		int cnt = 0;
		for(int i=0;i<n;i++) if(s[i]=='1') cnt++;
		if(cnt&1){
			cout<<"No\n";
		}else{
			cout<<"Yes\n";
			int shift = 0;
			for(;shift<n;shift++){
				if(s[shift]=='1') break;
			}
			bool flag = 0;
			for(int i=1;i<n;i++){
				if(!flag){
					cout<<(shift+1)%n+1<<" "<<(i+shift+1)%n+1<<"\n";
					flag=1;
				}else{
					cout<<(i+shift-1)%n+1<<" "<<(i+shift)%n+1<<"\n";
				}
				if(s[(shift+i)%n]=='1') flag =0;
			}
		}

	}

	return 0;
}
