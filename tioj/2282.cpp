#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
const int MOD = 1e9+7;
const int N = 23;

int dp[1<<N][2];


struct e{
	int a,b,w;
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int k,n;cin>>k>>n;
	dp[0][1]=1;dp[0][0]=1;
	e arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].a>>arr[i].b>>arr[i].w;
		if(arr[i].a>arr[i].b) swap(arr[i].a,arr[i].b);
	}
	sort(arr,arr+n,[](const e &x,const e &y){return x.a<y.a;});	

	for(int i=0;i<n;i++){
		int a = arr[i].a-1;int b= arr[i].b-1;	
		for(int s=0;s<(1<<(k-a));s++){
			dp[s][1] = (dp[s][1]+((1LL*dp[s^(1<<(k-a-1))^(1<<(k-b-1))][0]*arr[i].w)%MOD))%MOD;
		}
		for(int s=0;s<(1<<(k-a));s++) dp[s][0]=dp[s][1];
	}
	cout<<dp[0][0]-1<<"\n";
		

	return 0;
}
