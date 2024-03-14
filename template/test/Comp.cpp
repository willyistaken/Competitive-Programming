#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	vector<pair<int,int> > arr(n);
	for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;
	int a,b;cin>>a>>b;
	if(a!=b){
		cout<<n<<"\n";
		for(auto i : arr) cout<<i.first<<" "<<i.second<<"\n";
		cout<<a<<" "<<b<<"\n";
		cout<<"----\n";
	}

	return 0;
}
