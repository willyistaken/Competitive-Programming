#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n  =20;
	srand(time(0));
	cout<<n<<"\n";
	for(int i=0;i<n;i++){
		bool g = (rand()%2);
		int k = (g)?(-1):(1);
		cout<<k*(rand()%21)<<" ";
	}
	cout<<"\n";
	return 0;
}
