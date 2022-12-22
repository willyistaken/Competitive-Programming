#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


double get(int a,int b){
	double r = 0;
	for(int i=1;i<=a;i++){
		r+= ((double)min(i-1,b)/(double)(a*b));
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	double ans = 0;
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		for(int j=i-1;j>=0;j--){
			ans+=get(arr[j],arr[i]);
		}
	}
	cout<<fixed<<setprecision(6)<<ans<<"\n";

	return 0;
}
