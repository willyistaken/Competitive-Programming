#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int q;cin>>q;
	bool aonlya = 1,bonlya = 1;
	ll asize = 1;ll bsize = 1;
	while(q--){
		int d;cin>>d;
		int k;cin>>k;
		string s;cin>>s;
		if(d==1){
			if(aonlya==1){
			for(auto c : s){
				if(c!='a'){
					aonlya=0;
					break;
				}
			}
			}
			asize+=1LL*k*s.size();
		}else{
			if(bonlya==1){
				for(auto c :s){
					if(c!='a'){
						bonlya = 0;
						break;
					}
				}
			}
			bsize+=1LL*k*s.size();
		}
		if(bonlya==0){
			cout<<"Yes\n";
		}else{
			if(aonlya==1 && asize<bsize){
				cout<<"Yes\n";
			}else{
				cout<<"No\n";
			}
		}
	}
	return ;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
