#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int n;cin>>n;
	string a,b;cin>>a>>b;
	int num0 = 0;
	int num1 = 0;	
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]) num0++;
		if(a[i]!=b[n-i-1]) num1++;
	}
	if(num0==0){
		cout<<0<<"\n";
		return ;
	}
	if(num1==0){
		cout<<2<<"\n";
		return ;
	}
	if(num1%2){
		num1*=2;
	}else{
		num1*=2;num1--;
	}
	if(num0%2){
		num0*=2;num0--;
	}else{
		num0*=2;
	}
	cout<<min(num0,num1)<<"\n";
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
