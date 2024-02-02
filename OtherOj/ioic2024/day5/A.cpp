#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	map<int,int> s;
	int maxn = 0;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		s[a]++;
		maxn = max(maxn,a);
	}
	for(auto i : s){
		if(i.second>2)	{
			cout<<"No\n";
			return 0;
		}
	}
	if(s[maxn]>1){
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
	return 0;
}
