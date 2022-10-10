#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int m = 7*24;
	int n = 7;
	int r= 1;
	for(int i=0;i<=10;i++){
		cout<<i<<" "<<r<<"\n";
		r = (1LL*n*r)%m;
	}

	return 0;
}
