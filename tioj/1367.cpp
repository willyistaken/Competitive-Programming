#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int m;
	while(cin>>m){
	int a[m],b[m];
	for(int i=0;i<m;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	sort(a,a+m);
	sort(b,b+m,greater<int>());
	ll sum=0;
	for(int i=0;i<m;i++){
		sum+=(a[i]*b[i]);
	}
	cout<<sum<<"\n";
	}
	return 0;
}
