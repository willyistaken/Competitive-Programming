#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 5;
int phi[MAXN];int pn[MAXN];vector<int> prime;
ll phisum[MAXN];
void init(){
	phi[0]=1;
	phi[1]=1;
	phisum[0]=1;
	phisum[1]=2;
	for(int i=2;i<MAXN;i++){
		if(!pn[i]){
			prime.push_back(i);
			phi[i]=i-1;
			pn[i]=i;
		}
		for(int k=0;k<prime.size() && prime[k]<=pn[i] && prime[k]*i<MAXN ;k++){
			pn[prime[k]*i]=prime[k];
			phi[prime[k]*i] = ((i%prime[k]==0)?(prime[k]*phi[i]):(prime[k]-1)*(phi[i]));
		}
		phisum[i]=phisum[i-1]+phi[i];
	}
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	init();
	int n;
	while(cin>>n && n>0) cout<<2*phisum[n]-1<<"\n";

	return 0;
}

// linear sieve on euler's function
