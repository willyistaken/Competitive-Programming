#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	if(m>n){
		cout<<"NE\n";
		return 0;
	}
	int minn = 1e9;
	int sum = 0;
	for(int i=0;i<m;i++){
		int a;cin>>a;
		minn= min(a,minn);
		sum+=a/4;
	}
	if(sum<n || minn<4){
		cout<<"NE\n";
		return 0;
	}
	cout<<"DA\n";

	return 0;
}
