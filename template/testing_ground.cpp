#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <bit>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i=1;i<=100;i++){
		if(__builtin_popcount(i)>__lg(i)+1-__builtin_popcount(i)) cout<<i<<endl;
	}



	return 0;
}
