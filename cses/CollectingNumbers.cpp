#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;	
	vector<int> pos(n+1,0);
	for(int i=0;i<n;i++) {
		int a;cin>>a;
		pos[a] = i;
	}
	int ans = 0;
	int prev = pos[1];
	for(int i=2;i<=n;i++){
		if(pos[i]<prev) ans++;
		prev = pos[i];
	}
	cout<<ans+1<<"\n";
	return 0;
}
