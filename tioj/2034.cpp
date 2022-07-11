#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int minn=INT_MAX;
	int maxn=INT_MIN;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		minn = min(minn,a);
		maxn = max(maxn,a);
	}
	cout<<minn<<" "<<maxn<<" "<<((maxn-minn+1==n)?"yes\n":"no\n");
	return 0;
}
