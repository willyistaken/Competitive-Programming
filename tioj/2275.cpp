#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,k;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	vector<int> kpos;
	string s;cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='1') kpos.push_back(i+1);
	}
	ll sum[n+1]={0};
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		sum[i] = sum[i-1]+a;
	}
	ll ans=0;
	deque<int> dq;
	dq.push_back(0);
	for(int i=1;i<=n;i++){	
		int total = upper_bound(kpos.begin(),kpos.end(),i)-kpos.begin();
		int l = (total-k-1<0)?(0):(kpos[total-k-1]);
		while(dq.size()){
			if(dq.front()<l) dq.pop_front();
			else break;
		}
		//cout<<i<<" "<<dq.front()<<"\n";
		ans = max(ans,sum[i]-sum[dq.front()]);
		while(dq.size()){
			if(sum[dq.back()]>=sum[i]) dq.pop_back();
			else break;
		}
		dq.push_back(i);
		//cout<<l<<" ";
	
	}
	cout<<ans<<"\n";
}
