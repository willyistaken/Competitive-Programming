#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


struct line{
	ll a,b;
};

bool worse(line a,line b,ll x){
	return (a.a*x+a.b)>=(b.a*x+b.b);
}
bool worser(line a,line b,line c){
	ll abxt = -a.b+b.b;	
	ll abxd = a.a-b.a;
	ll bcxt = -a.b+c.b;
	ll bcxd = a.a-c.a;
	return (abxt*bcxd)>=(bcxt*abxd);
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,x;cin>>n>>x;		
	ll dp[n];		
	ll s[n];
	ll f[n];
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<n;i++) cin>>f[i];
	deque<line> q;
	q.push_back({x,0});
	for(int i=0;i<n;i++){
		while(q.size()>1){
			if(worse(q[0],q[1],s[i])) q.pop_front();
			else break;
		}
		line b = q.front();
		dp[i] = b.a*s[i]+b.b;
		line w = {f[i],dp[i]};
		bool k = 0;
		while(q.size()>1){
			if(w.a==q[q.size()-1].a){
				if(w.b>q[q.size()-1].b){
					k=1;
					break;
				}else{
					q.pop_back();
					continue;
				}
			}
			if(worser(q[q.size()-2],q[q.size()-1],w)) q.pop_back();
			else break;
		}
		if(!k) q.push_back(w);
	}
	cout<<dp[n-1]<<"\n";
	return 0;
}
