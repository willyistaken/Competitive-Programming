#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

bitset<200005> used;

void solve(){
	int n,x;cin>>n>>x;
	if(n%x!=0){
		cout<<-1<<"\n";
		return ;
	}
	int ans[n+1];
	for(int i=1;i<=n;i++) ans[i] = i;
	swap(ans[1],ans[n]);
	if(ans[1]!=x) swap(ans[x],ans[1]);
	int pos = x;		
	for(int i = pos+1;i<n;i++){
		if(ans[i]%pos==0 && ans[pos]%i==0) {
			swap(ans[i],ans[pos]);
			pos = i;
		}
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
