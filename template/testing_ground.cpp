#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i=1;i<=100;i++){
		cout<<i<<" "<<((((i*i-i))/2)%i)<<"\n";
	}
	return 0;
}