#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		bool a,b,c,d;cin>>a>>b>>c>>d;
		int sum = a+b+c+d;
		if(sum==0){
			cout<<0<<"\n";
			continue;
		}
		if(sum==1){
			cout<<1<<"\n";
			continue;
		}
		if(sum==2){
			cout<<1<<"\n";
			continue;
		}
		if(sum==3){
			cout<<1<<"\n";
			continue;
		}
		if(sum==4){
			cout<<2<<"\n";
		}
	}

	return 0;
}
