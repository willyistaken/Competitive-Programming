#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


const int N = 1e6+5;
int notprime[N];
void init(){
	notprime[1]=1;
	for(int i=2;i<N;i++){
		if(!notprime[i]){
			for(int j=i+i;j<N;j+=i) notprime[j]=1;
		}
	}
	for(int i=1;i<N;i++){
		if(!notprime[i]) notprime[i]=notprime[i-1]+1;
		else notprime[i]=notprime[i-1];
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	init();
	int q;cin>>q;
	while(q--){
		int n;cin>>n;
		cout<<notprime[n]-notprime[(n/2)]<<"\n";
	}
	return 0;
}
