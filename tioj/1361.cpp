#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int f(int n){
	if(n<0) return 0;
	int ans=0;
	int t = 1;
	int r = 1;
	while(n){
		if(n%10){
			ans+=(n/10)*r;
		}else{
			ans+=t+(n/10 - 1)*r;
		}
		t+=r*(n%10);
		r*=10;
		n/=10;
	}
	return ans+1;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a,b;
	while(cin>>a>>b){
		if(a>b) swap(a,b);
		cout<<f(b)-f(a-1)<<"\n";
	}



	return 0;
}
