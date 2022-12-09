#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int a;cin>>a;
	map<int,pair<int,int> > s;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(s.count(a-arr[i]-arr[j])){
				int v = a-arr[i]-arr[j];
				cout<<i+1<<" "<<j+1<<" "<<s[v].first+1<<" "<<s[v].second+1<<"\n";
				return 0;
			}
		}
		for(int k = 0;k<i;k++){
			s[arr[i]+arr[k]] = {k,i};
		}
	}
	cout<<"IMPOSSIBLE\n";
	return 0;
}
