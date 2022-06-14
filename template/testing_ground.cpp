#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int nextpowerofn(int n){
	n |= n>>1;
	n|= n>>2;
	n|= n>>4;
	n|= n>>8;
	n|= n>>16;
	n|= n>>31;
	return n+1;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i=0;i<=100;i++){
		cout<<i<<" "<<nextpowerofn(i)<<endl;
	}







	return 0;
}