#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int w,h,k;cin>>w>>h>>k;	
	if(k){
		cout<<"NO\n";
		return 0;
	}
	if(w%2==0 && h%3==0){
		cout<<"YES\n";
		return 0;
	}
	if(h%2==0 && w%3==0){
		cout<<"YES\n";
		return 0;
	}
	if(w%6==0 || h%6==0){
		cout<<"YES\n";
		return 0;
	}
	cout<<"NO\n";
	
	return 0;
}
