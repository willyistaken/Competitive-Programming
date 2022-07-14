#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	srand(time(0));
	int n = rand();
	n%=50;
	cout<<n<<"\n";
	int a[n];
	int b[n]; 
	for(int i=1;i<=n;i++) a[i-1]=b[i-1]=i;
	random_shuffle(a,a+n);
	random_shuffle(b,b+n);
	for(int i=0;i<n;i++) cout<<a[i]<<" \n"[i==n-1];
	for(int i=0;i<n;i++) cout<<b[i]<<" \n"[i==n-1];
}
