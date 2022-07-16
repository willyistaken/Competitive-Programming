#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	int arr[m+1];
	memset(arr,0,sizeof(arr));
	int maxn=INT_MIN;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int k;cin>>k;
			arr[j]=max({arr[j],arr[j-1],0})+k;
			if(i==n || j==m) maxn = max(maxn,arr[j]);
		}
	}
	cout<<maxn<<"\n";
	return 0;
}
