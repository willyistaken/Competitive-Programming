#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


const int N = 45;
int deg[N];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	if(n==1){
		cout<<1<<"\n";
		return 0;
	}
	for(int i=0;i<n-1;i++)	{
		int a,b;cin>>a>>b; 
		deg[a]++;
		deg[b]++;
	}
	int maxn = 0;
	for(int i=1;i<=n;i++) maxn = max(maxn,deg[i]);
	cout<<maxn<<"\n";

	return 0;
}
