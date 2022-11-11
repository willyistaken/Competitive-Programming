#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int a,b,c;cin>>a>>b>>c;
		int sum  = a+b+c;
		if(sum-c==c || sum-a==a || sum-b==b){
			cout<<"yes\n";
		}else{
			cout<<"no\n";
		}
	}

	return 0;
}
