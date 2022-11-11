#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<int> co[1001];

void init(){
	for(int i=1;i<1001;i++){
		for(int j = 1;j<1001;j++){
			if(__gcd(i,j)==1){
				co[i].push_back(j);
			}
		}
	}
}
int loc[1001];
void solve(){
	int n;cin>>n;
	memset(loc,0,sizeof(loc));
	int maxn = 0;
	for(int i = 1;i<=n;i++){
		int a;cin>>a;
		loc[a] = i;
		for(auto j : co[a]){
			if(loc[j]) maxn = max(loc[j]+i,maxn);
		}
	}
	if(maxn) cout<<maxn<<"\n";
	else cout<<-1<<"\n";
	return ;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	init();
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
