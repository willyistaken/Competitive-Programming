#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000005;
vector<int> prime;
bitset<maxn> notprime;
void init(){
for(int i=2;i<maxn;i++){
	if(!notprime[i]){
		prime.push_back(i);
		for(int j=2;j*i<maxn;j++){
			notprime[j*i]=1;
		}
	}
}
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	init();
	int a,b;
	while(cin>>a>>b){
	if(a>b) swap(a,b);
	int ans = upper_bound(prime.begin(),prime.end(),a)-prime.begin();
	ll other=1;
	for(int i=a+1;i<=b;i++){
		other*=i;
	}
	other++;
	for(auto p:prime){
		if(other%p==0){
			if(p>a) ans++;
			while(other%p==0) other/=p;
		}
	}
	if(other>=maxn) ans++;
	cout<<ans<<"\n";
	}
	return 0;
}
