#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


// dp[n][k] = dp[j][k-1] + si^2+sj^2-2sisj;

struct line{
	ll m;ll b;
	ll operator()(ll x){
		return m*x+b;
	}
};

bool worse(line s,line a,line b){
	ll sat = a.b-s.b;
	ll sad = s.m-a.m;
	ll sbt = b.b-s.b;
	ll sbd = s.m-b.m;
	return sbt*sad<sat*sbd;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	ll dp[n+1] ={0};		
	ll temp[n+1]={0};
	ll sum[n+1]={0};
	for(int i=1;i<=n;i++){
		cin>>sum[i];
		sum[i]+=sum[i-1];
		temp[i] = sum[i]*sum[i];
	}
	for(int i=2;i<=k;i++){
		deque<line> q;	

		for(int j=1;j<=n;j++){
			if(j<i){
				dp[j] = 1e15;
			}else{
				while(q.size()>1){
					if(q[0](sum[j])>q[1](sum[j])) q.pop_front();
					else break;
				}
				dp[j] = q[0](sum[j])+(sum[j]*sum[j]);
			}
			line nl = {-2*sum[j],temp[j]+(sum[j]*sum[j])};
			while(q.size()>1){
				if(worse(q[q.size()-2],q[q.size()-1],nl)) q.pop_back();	
				else break;
			}
			q.push_back(nl);
			//cout<<dp[j]<<' ';
		}
		for(int g=0;g<=n;g++) temp[g] = dp[g];
		//cout<<"\n";
	}
	cout<<dp[n]<<"\n";
	return 0;
}
