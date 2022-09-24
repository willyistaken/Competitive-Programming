#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,d,r;
	while(cin>>n>>d>>r){
		int mor[n],aft[n];
		for(int i=0;i<n;i++) cin>>mor[i];
		for(int i=0;i<n;i++) cin>>aft[i];
		sort(mor,mor+n);
		sort(aft,aft+n,greater<int>());
		ll ans=0;
		for(int i=0;i<n;i++){
			ans+=(mor[i]+aft[i]>d)?(mor[i]+aft[i]-d):(0);
		}
		cout<<ans*r<<"\n";
	}

	return 0;
}
