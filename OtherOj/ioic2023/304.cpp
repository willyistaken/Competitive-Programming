#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 150005;
ll dp[N][2];
struct event{
	int a=0;
	int b=0;
	int t=0;
} a[305];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,d;cin>>n>>m>>d;
	for(int i=1;i<=m;i++){
		cin>>a[i].a>>a[i].b>>a[i].t;
	}
	sort(a+1,a+m+1,[](const event &a,const event &b){return a.t<b.t;});
	for(int i=1;i<=m;i++){
		deque<int> dq;
		ll dis = 1LL*d*(a[i].t-a[i-1].t);
		int k = 1;
		for(int j=1;j<=n;j++){
			while(dq.size()){
				if(abs(j-dq.front())>dis) dq.pop_front();
				else break;
			}
			while(abs(k-j)<=dis && k<=n){
				while(dq.size()){
					if(dp[dq.back()][(i%2)^1]<=dp[k][(i%2)^1])  dq.pop_back();
					else break;
				}
				dq.push_back(k++);
			}
			dp[j][i%2] = dp[dq.front()][(i%2)^1]+a[i].b-abs(a[i].a-j);
		}
	}
	ll maxn = LONG_LONG_MIN;
	for(int i=1;i<=n;i++){
		maxn = max(maxn,dp[i][m%2]);
	}
	cout<<maxn<<"\n";
	return 0;
}
