#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


string ans[2]={"ne","da"};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	string s;cin>>s;
	string b;cin>>b;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		arr[i] = (b[i]-s[i]);
	}
	vector<int> u(n);
	u[n-1]=-1;
	for(int j=n-2;j>=0;j--) u[j]=u[j+1]*-1;
	ll sum=0;	
	for(int i=0;i<n;i++) sum+=u[i]*arr[i];
	cout<<ans[sum%26==0]<<"\n";
	for(int i=0;i<q;i++){
		int p;cin>>p;
		p--;
		char x;cin>>x;
		ll og = u[p]*arr[p];
		s[p]=x;
		arr[p] = b[p]-s[p];
		sum-=og;
		sum+=u[p]*arr[p];
		cout<<ans[sum%26==0]<<"\n";
	}
	return 0;
}
