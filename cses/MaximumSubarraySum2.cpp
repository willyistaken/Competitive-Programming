#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int a,b;cin>>a>>b;
	ll sum[n+1]={0};
	for(int i=1;i<=n;i++){
		cin>>sum[i];
		sum[i]+=sum[i-1];
	}
	deque<int> mono;
	ll ans = LONG_LONG_MIN;
	for(int i=0;i<=n;i++){
		while(mono.size() && mono.front()<i-b) mono.pop_front();
		if(i-a>=0){
			while(mono.size()){
				if(sum[mono.back()]>=sum[i-a]) mono.pop_back();
				else break;
			}
			mono.push_back(i-a);
		}
		if(mono.size()) ans = max(ans,sum[i]-sum[mono.front()]);	
	}
	cout<<ans<<"\n";


	return 0;
}
