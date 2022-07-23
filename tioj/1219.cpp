#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 50005;
int u[MAXN];
int x[MAXN];
vector<int> prime;
void init(){
	x[1]=1;
	u[1]=1;
	for(int i=2;i<MAXN;i++){
		if(!x[i]){
			prime.push_back(i);
			x[i]=i;
			u[i]=-1;
		}
		for(int k=0;k<prime.size() && x[i]>=prime[k] && i*prime[k]<MAXN;k++){
			if(x[i]==prime[k]){
				u[i*prime[k]]=0;
				x[i*prime[k]]=prime[k];
			}else{
				u[i*prime[k]] = u[i]*-1;	
				x[i*prime[k]] = prime[k];
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	init();
	int a,b,d;
	while(cin>>a>>b>>d &&(a||b||d)){
		a = a/d;
		b = b/d;
		int maxn = min(a,b);
		int ans=0;
		for(int i=1;i<=maxn;i++){
			ans+=(u[i]*(a/i)*(b/i));
		}
		cout<<ans<<"\n";
	}
	return 0;
}

//mobius inversion
