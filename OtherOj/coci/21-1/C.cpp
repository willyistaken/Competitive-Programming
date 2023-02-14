#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int a,b;cin>>a>>b;
	}
	if(n%4){
		cout<<-1<<"\n";
	}else{
		cout<<n/2<<"\n";
	}

	return 0;
}
