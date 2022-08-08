#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int MAXN = 10;
	int ans[MAXN]={0};
	ans[0]=1;
	for(int i=0;i<MAXN;i++){
		cout<<ans[0]<<" ";
		for(int j=1;j<MAXN;j++){
			ans[j] = ans[j]+ans[j-1];
			cout<<ans[j]<<" ";
		}
		cout<<"\n";
	}
	cout<<ans[MAXN-1]<<"\n";

	return 0;
}
