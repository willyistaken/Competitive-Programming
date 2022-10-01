

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
		int ans=0;
	for(int i=1;i<=100;i++){
		//cout<<i<<" "<<__builtin_popcount(i)<<" "<<__lg(i)<<"\n";
		if(2*__builtin_popcount(i)>__lg(i)+1) ans++;
		cout<<i<<" "<<ans<<"\n";
	}

	return 0;
}
