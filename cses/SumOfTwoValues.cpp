#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,x;cin>>n>>x;
	map<int,int> s;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		if(s.count(x-a)){
			cout<<i+1<<" "<<s[x-a]<<"\n";
			return 0;
		}
		s.insert({a,i+1});
	}
	cout<<"IMPOSSIBLE\n";
	return 0;
}
