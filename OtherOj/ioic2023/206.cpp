#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<int> prime;
const int N = 1e6+5;
bool notprime[N];
void init(){
	for(int i=2;i<N;i++){
		if(!notprime[i]){
			prime.push_back(i);
			for(int j = 2*i;j<N;j+=i){
				notprime[j]=1;
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	init();
	while(t--){
		int x;cin>>x;
		for(auto p : prime){
			if(!notprime[x-p]){
				cout<<p<<" "<<x-p<<"\n";
				break;
			}
		}
	}

	return 0;
}
