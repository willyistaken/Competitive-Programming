#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	bool notprime[n+1]={0};
	notprime[1]=1;
	for(int i=2;i<=n;i++){
		if(!notprime[i]){
			for(int j=2;j*i<=n;j++){
				notprime[j*i]=1;
			}
		}
	}
	for(int i=n;i>=1;i--){
		if(notprime[i]==notprime[n]) cout<<i<<" ";
	}
	cout<<"\n";
	return 0;
}
