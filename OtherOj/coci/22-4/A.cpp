#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int arr[115];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	string s;cin>>s;
	arr[100]=0;
	arr[107]=1;
	arr[111]=2;
	arr[114]=3;
	int cnt[4]={0,0,0,0};
	for(int i=0;i<n;i++){
		cnt[arr[(int)s[i]]]++;
	}
	ll maxn = 0;
	for(int mask=0;mask<(1<<(2*m));mask++){
		for(int i=0;i<2*m;i+=2)	{
			cnt[(2*((mask>>i)&1)+((mask>>(i+1))&1))]++;
		}
		int sum = 0;
		int minn = 1e9;
		for(int i=0;i<4;i++){
			if(i==3 || i==0) minn = min(minn,cnt[i]);
			else minn = min(minn,cnt[i]/2);
			sum+=(cnt[i]*cnt[i]);
		}
		maxn = max(maxn,sum+minn*7LL);
		for(int i=0;i<2*m;i+=2)	{
			cnt[(2*((mask>>i)&1)+((mask>>(i+1))&1))]--;
		}
	}
	cout<<maxn<<"\n";
	return 0;
}
