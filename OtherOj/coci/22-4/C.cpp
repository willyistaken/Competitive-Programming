#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


vector<vector<int> >  dp[11][11];
const int MOD = 1e9+7;

int po(int a,int p){
	ll r = 1;
	while(p){
		if(p&1) r = (r*a)%MOD;
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}

void mul(vector<vector<int> > &a,vector<vector<int> > &b){
	int n = a.size();
	vector<vector<int> > r(n,vector<int>(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				r[i][j] += (1LL*a[i][k]*b[k][j])%MOD;
				r[i][j]%=MOD;
			}
		}
	}
	a = r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll t;
	int n,K;cin>>n>>t>>K;
	dp[0][0].push_back(vector<int>(0));
	for(int i=1;i<=n;i++){
		for(int k=1;k<=i;k++){
			for(int j=k;j>=0;j--){
				vector<vector<int> > v = dp[i-k][j];
				for(auto u : v){
					u.push_back(k);
					dp[i][k].push_back(u);
				}
			}
		}
	}
	int cnt = 0;
	vector<vector<int> > arr;
	map<vector<int>,int> mp;
	for(int i=1;i<=n;i++){
		for(auto j :dp[n][i]){
			mp[j]=cnt++;
			arr.push_back(j);
		}
	}
	const int revn2 = po(n*n,MOD-2);
	vector<vector<int> > M(cnt,vector<int>(cnt,0));
	for(int g=0;g<cnt;g++){
		int sz = arr[g].size();
		for(int i=0;i<sz;i++){
			for(int j=0;j<sz;j++){
				int prob = (1LL*arr[g][i]*arr[g][j]*revn2)%MOD;
				vector<int> w = arr[g];
				w[i]++;
				w[j]--;
				sort(w.rbegin(),w.rend());
				while(w.back()==0) w.pop_back();
				reverse(w.begin(),w.end());
				int T = mp[w];
				M[g][T] = (M[g][T]+prob)%MOD;
			}
		}
	}
	vector<vector<int> > r(cnt,vector<int>(cnt,0));
	for(int i=0;i<cnt;i++) r[i][i]=1;
	while(t){
		if(t&1)	mul(r,M);
		mul(M,M);
		t>>=1;
	}
	int ans = 0;
	for(int i=0;i<cnt;i++){
		if(arr[i].size()>=K) ans=(ans+r[0][i])%MOD;
	}
	cout<<ans<<"\n";
	return 0;
}
