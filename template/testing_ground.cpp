#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int f[10000]={0};
	f[1]=1;
	f[2]=2;
	f[3]=3;
	for(int i=3;f[i]>0;i++){
		f[i+1]=f[i]+f[i-1];
		cout<<f[i+1]<<endl;	
	}







	return 0;
}