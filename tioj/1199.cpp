#include<bits/stdc++.h>
using namespace std;
#define ll long long

int power(int x,int n,int y){
	if(x==0 && n==0) return -1;
	if(n==0) return 1;
	if(n==1) return (x%y);
	if(n==2) return((1LL*x*x)%y);
	if(n%2) return ((power(x,n-1,y)*x)%y);
	return (power(x,n/2,y)*power(x,n/2,y))%y;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a,n,y;
	while(cin>>a>>n>>y && ( a || n || y )){
		int ans=0;
		for(int i=(n==0);i<y;i++){
			if(power(i,n,y)==a) ans++;
		}
		cout<<ans<<endl;

	}
	
	return 0;
}
