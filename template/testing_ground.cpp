#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


void x(int a,int b){
	for(int i=1;i<=max(a,b);i++){
		if(a%i==0 && b%i==0) continue;
		if(a%i==0 || b%i==0) cout<<i<<" ";
	}
	cout<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=1;i<=100;i++){
		for(int j=i;j<=100;j++){
			cout<<i<<","<<j<<":";x(i,j);
		}
	}
		

	return 0;
}
