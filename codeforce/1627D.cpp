#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


bitset<1000005> in;
int gcdofk[1000005];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		in[a]=1;
	}
	int cnt = 0;
	for(int i=1;i<=1000000;i++){
		for(int j=i;j<=1000000;j+=i){
			if(in[j]) gcdofk[i] = __gcd(gcdofk[i],j);
		}
		if(in[i] || gcdofk[i]==i) cnt++;
	}
	cout<<cnt-n<<"\n";
	return 0;
}
