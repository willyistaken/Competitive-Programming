#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 1e7+10;
vector<int> prime;
int highp[N];
void init(){
	for(int i=2;i<N;i++){
		if(!highp[i]){prime.push_back(i);
		for(int j=i;j<N;j+=i) highp[j] = prime.size();
		}
	}
}
vector<ll> cnt;
ll cntstuff[N];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	init();
	cnt.resize(prime.size());
	for(int i=0;i<n;i++){
		int a;cin>>a;
		cntstuff[a]+=1;
	}
	for(int i = N-2;i>=1;i--){
		cntstuff[i] += cntstuff[i+1];
		int v = i;
		while(highp[v]){
			int ind = highp[v]-1;
			int p = prime[ind];
			while(v%p==0){
				cnt[ind]+=cntstuff[i];
				v/=p;
			}
		}
	}
	memset(cntstuff,0,sizeof(cntstuff));
	for(int i=0;i<m;i++){
		int b;cin>>b;
		cntstuff[b]+=1;
	}
	for(int i=N-2;i>=1;i--){
		cntstuff[i] +=cntstuff[i+1];
		int v = i;
		while(highp[v]){
			int ind = highp[v]-1;
			int p = prime[ind];
			while(v%p==0){
				cnt[ind]-=cntstuff[i];
				if(cnt[ind]<0){
					cout<<"No\n";
					return 0;
				}
				v/=p;
			}
		}
	}
	cout<<"Yes\n";
	return 0;
}
