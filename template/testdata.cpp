#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	srand( time(NULL) );
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n = 10;
	int k = 0;
	int M = 1e9+1;
	int l = rand()%M;
	int r = rand()%M;
	if(l>r) swap(l,r); 
	cout<<n<<" "<<k<<"\n";
	int dig[n];
	for(int i=0;i<n;i++) dig[i]=i;
	random_shuffle(dig,dig+n);
	for(int i=0;i<k;i++){
		cout<<dig[i]<<" \n"[i==k-1];	
	}
	cout<<l<<" "<<r<<"\n";
}
