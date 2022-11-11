#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int p = 2;
	int cnt = 0;
	while(p<=n){
		cnt+=n/p;
		p = p*2;
	}
	p = 5;
	int cnt2=0;
	while(p<=n){
		cnt2+=n/p;
		p  = p*5;
	}
	cout<<min(cnt,cnt2)<<"\n";
	return 0;
}
