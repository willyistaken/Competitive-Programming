#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,t;cin>>n>>t;
	if(t!=10){
		for(int i=0;i<n;i++) cout<<t;
		cout<<"\n";
	}else{
		if(n==1){
			cout<<-1<<"\n";
			return 0;
		}
		cout<<1;
		for(int i=1;i<n;i++) cout<<0;
		cout<<"\n";
	}

	return 0;
}
