#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int n,m;cin>>n>>m;
	int typecnt[n+1]={0};
	for(int i=0;i<n;i++){
		int a;cin>>a;
		typecnt[a]++;
	}
	int table[m];			
	for(int i=0;i<m;i++) cin>>table[i];
	sort(table,table+m);
	priority_queue<int> pq;	
	for(int i=1;i<=n;i++){
		if(typecnt[i]) pq.push(typecnt[i]);
	}
	int ans = 0;
	for(int i=m-1;pq.size() && i>=0;i--){
		int cnt = pq.top();
		pq.pop();
		if(table[i]>cnt){
			ans+=cnt;
		}else{
			ans+=table[i];
			cnt-=table[i];
			pq.push(cnt);
		}
	}
	cout<<ans<<"\n";
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
