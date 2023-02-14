#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n = 2e5;
	int m = (n-1)*2;
	cout<<n<<" "<<m<<"\n";
	for(int i=2;i<=n;i++){
		cout<<1<<" "<<i<<"\n";
		cout<<i<<" "<<1<<"\n";
	}
	return 0;
}
