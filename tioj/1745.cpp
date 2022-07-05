#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b,c;
ll f(ll x){
	return (a*x*x)+(b*x)+c;
}

bool comp(pair<ll,ll> &a,pair<ll,ll> &b,ll xi){
	return a.first*xi+a.second<=b.first*xi+b.second;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>a>>b>>c;
	ll sum[n+1]={0};
	ll dp[n+1]={0};
	for(int i=0;i<n;i++){
		int k;cin>>k;
		sum[i+1]=sum[i]+k;
	}
	deque<pair<ll,ll> > dq;
	dq.push_back({0,0});
	for(int i=1;i<=n;i++){
		while(dq.size()>=2){
			pair<ll,ll>	pf = dq.front();
			dq.pop_front();
			pair<ll,ll> ps = dq.front();
			if(!comp(pf,ps,sum[i])){
				dq.push_front(pf);
				break;
			}
		}
		pair<ll,ll> temp = dq.front();
		dp[i] = temp.first*sum[i] + temp.second + f(sum[i]);	
		pair<ll,ll> add = {-2*a*sum[i],(dp[i]+(a*sum[i]*sum[i])-(b*sum[i]))};
		while(dq.size()>=2){
			pair<ll,ll> pf = dq.back();
			dq.pop_back();
			pair<ll,ll> ps = dq.back();
			if((ps.second-add.second)*(pf.first-ps.first)>(ps.second-pf.second)*(add.first-ps.first)){
				dq.push_back(pf);
				break;
			}
		}
		dq.push_back(add);
	}
	cout<<dp[n]<<"\n";

	return 0;
}



