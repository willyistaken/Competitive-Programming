#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define int ll
bool isprime(ll p){
	for(ll i=2;i<=sqrt(p);i++){
		if(p%i==0) return 0;
	}
	return 1;
}

bool twin(ll G){
	if(G==3) return 1;
	if(G%6==5){
		return (isprime(G+2))	;
	}else if(G%6==1){
		return isprime(G-2);
	}
	return 0;
}


signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll A,B;cin>>A>>B;
	if((twin(A)||A==2) && (twin(B)||B==2)){
		if(A==2){
			if(B%6==5 || B==3){
				cout<<3<<"\n";
				cout<<A<<" "<<B+2<<" "<<B<<"\n";
				return 0;
			}else{
				cout<<2<<"\n";
				cout<<A<<" "<<B<<"\n";
				return 0;
			}
		}
		if(B==2){
			if(A%6==5 || A==3){
				cout<<3<<"\n";
				cout<<A<<" "<<A+2<<" "<<B<<"\n";
				return 0;
			}else{
				cout<<2<<"\n";
				cout<<A<<" "<<B<<"\n";
				return 0;
			}
		}
		if(abs(A-B)==2){
			cout<<2<<"\n";
			cout<<A<<" "<<B<<"\n";
			return 0;
		}
		vector<int> ans;
		ans.push_back(A);
		if(A%6==5 || A==3){
			ans.push_back(A+2);
		}
		ans.push_back(2);
		if(B%6==5 || B==3){
			ans.push_back(B+2);
		}
		ans.push_back(B);
		cout<<ans.size()<<"\n";
		for(auto i : ans) cout<<i<<" ";
		cout<<"\n";
	}else{
		cout<<-1<<"\n";
	}
	return 0;
}
