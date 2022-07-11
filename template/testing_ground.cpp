#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int root(int x){
	if(x<10) return x;
	int sum=0;
	while(x){
		sum+=x%10;
		x/=10;
	}
	return root(sum);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=1;i<500;i++){
		cout<<root(i)<<"\n";
	}

	return 0;
}
