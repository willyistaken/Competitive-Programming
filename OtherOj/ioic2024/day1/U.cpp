#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds



int fun(int n,int m){
	if(n<=1) return 0;
	int ans = (fun(n-1,m)+m)%n;
	if(ans<0) ans+=n;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	cout<<fun(n,m)+1<<"\n";

	return 0;
}
