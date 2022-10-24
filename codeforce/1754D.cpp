#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,x;cin>>n>>x;
	int cnt[x+1]= {0};
	for(int i=0;i<n;i++){
		int a;cin>>a;
		cnt[a]++;
	}
	for(int i=1;i<x;i++){
		if(cnt[i]%(i+1)) {
			cout<<"No\n";
			return 0;
		}
		cnt[i+1]+=cnt[i]/(i+1);
	}
	cout<<"Yes\n";
	return 0;
}
