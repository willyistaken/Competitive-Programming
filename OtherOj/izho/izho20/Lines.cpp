#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;	cin>>n;
	int a[n];
	int b[n];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	int cnt = 0;
	for(int i=0;i<n;i++) cnt+=(a[i]>b[i]);
	cout<<cnt<<"\n";
	return 0;
}
