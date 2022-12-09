#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


const double PI = 3.1415926535;
const int MOD = 1e9+7;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	double ans = 1;
	for(int j=1;j<=m/2+(m%2);j++){
		for(int k=1;k<=n/2+(n%2);k++){
			double a = cos(PI*j/(m+1));
			double b = cos(PI*k/(n+1));
			ans*=(4*a*a+4*b*b);
		}
	}
	cout<<ans<<"\n";

	return 0;
}
