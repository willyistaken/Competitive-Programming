#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int get(int k){
	int r = 2;
	for(int i=2;i<k;i++){
		r = (1LL*r*2)%k;
		if(r==1){
			return i;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int maxn = 0;
	for(int i=2;i<=1000;i++){
		if(i%2 && i%5){
			cout<<get(i)<<" "<<i<<"\n";
		}
	}
	cout<<maxn<<"\n";

	return 0;
}
