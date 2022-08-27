#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int a[n],b[n];
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++) cin>>b[i];
		for(int i=0;i<n;i++){
			cout<<*lower_bound(b,b+n,a[i])-a[i]<<" ";
		}
		cout<<"\n";
		vector<int> nope;
		for(int i=1;i<n;i++){
			if(a[i]>b[i-1]) nope.push_back(i);
		}
		nope.push_back(n);
		for(int i=0;i<n;i++){
			int p = *upper_bound(nope.begin(),nope.end(),i);
			p--;
			cout<<b[p]-a[i]<<" ";
		}
		cout<<"\n";

	}

	return 0;
}
