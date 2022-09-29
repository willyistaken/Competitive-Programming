#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int f[100]={0};
	f[1]=1;
	for(int i=2;i<100;i++){
		f[i] = 4*f[i/2]+(f[i-1]/2);
		cout<<i<<","<<f[i]<<"\n";
	}

	return 0;
}
