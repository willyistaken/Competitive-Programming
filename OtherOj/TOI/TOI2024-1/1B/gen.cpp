#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t=1000;
	cout<<t-2<<"\n";
	random_device g;
	mt19937 r(g());
	for(int n=3;n<=t;n++){
	cout<<n<<"\n";
	for(int i=0;i<n;i++){
		cout<<1<<" ";
	}
	cout<<"\n";
	}

	return 0;
}
