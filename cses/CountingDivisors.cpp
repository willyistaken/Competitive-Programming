#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	while(n--){
		int x;cin>>x;
		int cnt = 0;
		int k = sqrt(x);
		for(int i=1;i<=k;i++){
			if(x%i==0) {
				cnt+=2;
			}
		}
		if(k*k==x) cnt-=1;	
		cout<<cnt<<"\n";
	}

	return 0;
}
