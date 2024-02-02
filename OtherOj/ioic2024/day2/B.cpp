#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 1e6+5;
ll faccnt[N];
void init(){
	for(int i=1;i<N;i++){
		for(int j=i+i;j<N;j+=i)	faccnt[j]++;
	}
}
int n;
void solve(){
	cin>>n;
	cout<<3*faccnt[n]+n<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	init();
	for(int i=1;i<N;i++) faccnt[i]+=faccnt[i-1];
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
