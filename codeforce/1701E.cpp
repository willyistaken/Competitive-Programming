#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int m,n;cin>>n>>m;
		string c;cin>>c;
		string s;cin>>s;
		int shead=0;
		int bestfromr=-1;
		int firstnot=m;
		bool has=0;
		for(int i=0;i<n;i++){
			if(c[i]==s[shead]){
				shead++;
				if(shead==m){
					bestfromr = i;	
					break;
				}
			}else{
				if(!has) firstnot = i;
				has=1;
			}
		}
		if(bestfromr<0){
			cout<<-1<<"\n";
			continue;
		}
		shead=m-1;
		int bestfromback=-1;
		int lastnot=n-m-1;
		has=0;
		for(int i=n-1;i>=0;i--){
			if(c[i]==s[shead]){
				shead--;
				if(shead<0){
					bestfromback=i;
					break;
				}
			}else{
				if(!has) lastnot=i;
				has=1;
			}
		}
		int ans = min(n-firstnot,lastnot+2+n-m);
		cout<<ans<<"\n";





	}

	return 0;
}
