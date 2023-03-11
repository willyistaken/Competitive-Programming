#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


ll arr[505][505];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll R,S,a,b;cin>>R>>S>>a>>b;
	if(a>b) swap(a,b);
	for(int i=1;i<=R;i++){
		for(int j=1;j<=S;j++){
			cin>>arr[i][j];
		}
	}
	for(int j=1;j<=S;j++){
	for(int i=1;i<=R;i++){
		arr[i][j]+=arr[i-1][j];
	}
	}
	ll ans = 1e18;
	for(int l=1;l<=R;l++){
		for(int r = l;r<=R;r++){
			int p = 0;
			ll sum = 0;
			for(int i=1;i<=S;i++){
				ll e = arr[r][i]-arr[l-1][i];
				sum+=e;
				while(sum>b && p<=i){
					ans = min(abs(a-sum)+abs(b-sum),ans);
					sum-=arr[r][p]-arr[l-1][p];
					p++;
				}
				if(a<=sum && b>=sum){
					//cout<<sum<<"k\n";
					cout<<b-a<<"\n";
					return 0;
				}
				ans = min(abs(a-sum)+abs(b-sum),ans);
			}
		}
	}
	cout<<ans<<"\n";

	return 0;
}
