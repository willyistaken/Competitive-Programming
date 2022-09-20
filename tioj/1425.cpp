#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
int n,q;

char pfc[10000005];
ll sp[15];
void init(){
	sp[0]=1;
	for(int i=1;i<15;i++) sp[i] = sp[i-1]*16;
	pfc[1]=0;
	pfc[2]=1;
	vector<int> prime;
	prime.push_back(2);
	for(int i=3;i<=n;i++){
		if(!pfc[i]){
			prime.push_back(i);		
			pfc[i]=1;
		}
		for(int k=0;k<prime.size() && i*prime[k]<=n ;k++){
			if(i%prime[k]){
				pfc[i*prime[k]]	 = pfc[i]+1;		
			}else{
				pfc[i*prime[k]] = pfc[i];
			}
		}
	}
}

ll ans(int m){
	ll maxn = 0;
	for(int i=1;i<=m;i++){
		i = m/(m/i);	
		//cout<<sp[(int)pfc[m/i]]+i<<"\n";
		maxn = max(sp[(int)pfc[m/i]]+i,maxn);
	}
	return maxn;	
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;	
	init();
	while(q--){
		int a;cin>>a;
		cout<<ans(a)<<"\n";
	}

	return 0;
}
