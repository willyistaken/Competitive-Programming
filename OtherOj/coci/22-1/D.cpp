#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 1e7+5;
vector<int> prime;
int oddfaccnt[N];
int lowprime[N];
int elp[N];
void init(){
	oddfaccnt[1]=1;
	for(int i=2;i<N;i++){
		if(!lowprime[i]){
			prime.push_back(i);
			lowprime[i]=i;
			if(i!=2){
				oddfaccnt[i]=2;
			}else{
				oddfaccnt[i]=1;
			}
			elp[i]=1;
		}
		for(auto p : prime){
			if(p*i>=N) break;
			lowprime[p*i]=p;
			if(i%p==0){
				elp[p*i]=elp[i];
				if(elp[i]==1){
					if(p==2) oddfaccnt[p*i]=1;
					else oddfaccnt[p*i]=oddfaccnt[i]+1;
				}else{
					oddfaccnt[p*i] = oddfaccnt[elp[p*i]]*oddfaccnt[p*i/elp[p*i]];
				}
			}else{
				oddfaccnt[p*i] = oddfaccnt[p]*oddfaccnt[i];
				elp[p*i]=i;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	init();
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int x,y;cin>>x>>y;
		int k = __gcd(x,y);
		if(k==0){
			cout<<0<<"\n";
			continue;
		}
		x/=k;y/=k;
		if(x&1 && y&1) cout<<0<<"\n";
		else cout<<oddfaccnt[k]<<"\n";
	}

	return 0;
}
