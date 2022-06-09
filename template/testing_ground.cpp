#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	vector<int> prime;
	bitset<1000005> notprime;
	notprime.reset();
	for(int i=2;i<=1000000;i++){
		if(!notprime[i])	{
			for(int j=2;j*i<=1000000;j++) notprime[j*i]=1;	
			prime.push_back(i);
		}
	}
	int l,r;
	while(cin>>l>>r){
		int m=1;
		while(m<l)
	}




	return 0;
}
