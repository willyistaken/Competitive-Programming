#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int canmax=0;
	int k;cin>>k;
	for(int i=0;i<=k;i++){
		int a;cin>>a;
		if(canmax>=(1<<i)-1) canmax = canmax+(a*(1<<i));
		else {
			cout<<canmax+1<<"\n";
			return 0;
		}
	}
	cout<<canmax+1<<"\n";
	return 0;

	return 0;
}
