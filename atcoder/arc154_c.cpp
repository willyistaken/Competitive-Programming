#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

bitset<5005> cnt;
void solve(){
	int n;cin>>n;	
	vector<int> a(n),b(2*n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	for(int i=0;i<n;i++){
		cnt[i+1]=0;
		b[i+n]=b[i];
	}
	bool work=1;
	for(int i=0;i<n;i++) if(a[i]!=b[i]) work=0;
	if(work){
		cout<<"Yes\n";
		return ;
	}
	int acnt=0;
	for(int i=0;i<n;i++){
		if(cnt[a[i]]==0) acnt++;
		cnt[a[i]]=1;
	}
	for(int i=0;i<n;i++) cnt[i+1]=0;
	int bcnt=0;
	for(int i=0;i<n;i++){
		if(cnt[b[i]]==0) bcnt++;
		cnt[b[i]]=1;
	}
	
	for(int i=0;i<n;i++){
		vector<int> g;
		g.push_back(b[i]);
		for(int j=1;j<n;j++){
			if(b[i+j]!=b[i+j-1]){
				g.push_back(b[i+j]);
			}
		}
		if(g.size()==n) continue;
		int p = 0;
		for(int i=0;i<n&&p<g.size();i++){
			if(a[i]==g[p]) p++;
		}
		if(p==g.size()){
			cout<<"Yes\n";
			return ;
		}
	}
	cout<<"No\n";

}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
