#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 105;
int W[N][N];
int P[N];
int owner[N];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n && n){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) cin>>W[i][j];
		}
		for(int i=1;i<=n;i++){
			P[i]=0;
			owner[i]=0;
		}
		stack<int> q;
		for(int i=1;i<=n;i++) q.push(i);
		while(q.size()){
			int cur = q.top();
			q.pop();
			pair<int,int> maxn = {-1e9,0};
			for(int j=1;j<=n;j++) maxn = max(maxn,{W[cur][j]-P[j],j});
			if(maxn.first>=0){
				if(owner[maxn.second]) q.push(owner[maxn.second]);
				owner[maxn.second]=cur;
				else P[maxn.second]+=1;
			}
		}
		ll ans = 0;
		for(int i=1;i<=n;i++){
			if(owner[i]) ans+=(int)W[owner[i]][i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
