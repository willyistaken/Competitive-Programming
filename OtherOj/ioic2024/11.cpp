#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<vector<int>> arr;
vector<ll> ans;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;	
	arr.resize(n);
	ll sum = 0;
	for(int i=0;i<n;i++){
		arr[i].resize(m);
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			sum+=arr[i][j];
		}
	}
	for(int i=0;i<n;i++){
		sum+=arr[i][0]+arr[i][m-1];
	}
	for(int j=0;j<m;j++){
		sum+=arr[0][j]+arr[n-1][j];
	}
	ans.resize(n*m+1,-1);
	vector<ll> nsum(n-1,0);
	vector<ll> msum(m-1,0);
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m;j++){
			nsum[i]+=arr[i][j]+arr[i+1][j];
		}
	}
	for(int i=0;i<m-1;i++){
		for(int j=0;j<n;j++){
			msum[i]+=arr[j][i]+arr[j][i+1];
		}
	}
	sort(nsum.begin(),nsum.end(),greater<int>());
	sort(msum.begin(),msum.end(),greater<int>());
	ll ns = 0;
	for(int i=1;i<=n;i++){
		if(i>=2) ns+=nsum[i-2];
		ll ms = 0;
		for(int j=1;j<=m;j++){
			if(j>=2) ms+=msum[j-2];
			ans[i*j] = max(ans[i*j],ms+ns+sum);
		}
	}
	for(int i=1;i<=n*m;i++)	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
