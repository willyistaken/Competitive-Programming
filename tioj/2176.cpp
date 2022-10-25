#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n;
vector<int> a;
vector<int> b;
int u[100005];
int d[100005];
vector<int> prime;

void init(){
	u[1] = 1;
	for(int i = 2;i<=100003;i++){
		if(!d[i]){
			prime.push_back(i);
			d[i] = i;
			u[i] = -1;
		}
		for(int j = 0;j<prime.size() && i*prime[j]<=100003;j++){
			if(d[i]<prime[j]) break;
			d[i*prime[j]] = prime[j];
			u[i*prime[j]] = (d[i]==prime[j])?(0):(-u[i]);
		}
	}
}

ll c(int i){
	int N = n/i;
	ll sa[N+1] = {0};
	ll sb[N+1] = {0};
	for(int d=1;d<=N;d++){
		for(int k = 1;k*d<=N;k++){
			sa[d]+=a[k*d*i];
			sb[d]+=b[k*d*i];
		}
	}
	ll ans = 0;
	for(int d = 1;d<=N;d++){
		ans+=sa[d]*sb[d]*u[d];
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	init();
	cin>>n;
	a.resize(n+1);
	b.resize(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++){
		cout<<c(i)<<" ";
	}
	cout<<"\n";

	return 0;
}
