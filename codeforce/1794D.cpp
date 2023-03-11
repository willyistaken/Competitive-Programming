#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds



int dp[2050][2050];
const int N = 1e6+5;
const int MOD = 998244353;
bitset<N> notprime;
void init(){
	notprime[1]=1;
	for(int i=2;i<N;i++){
		if(notprime[i]){
			for(int j=i+i;j<N;j+=i){
				notprime[j]=1;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	init();
	map<int,int> P;
	map<int,int> NP;
	for(int i=0;i<2*n;i++){
		int a;cin>>a;
		if(notprime[a]){
			NP[a]++;
		}else{
			P[a]++;
		}
	}
	if(P.size()<n){
		cout<<0<<"\n";
		return 0;
	}
	vector<int> arr;
	arr.push_back(0);
	for(auto i : P){
		arr.push_back(i.second);
	}
	int m = arr.size();
	m--;
	for(int i=0;i<=m;i++) dp[i][0]=1;	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			dp[i][j] = dp[i-1][j]*()+dp[i-1][j-1]*(:)
		}
	}
	return 0;
}
