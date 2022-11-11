#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	multiset<int> s;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		s.insert(-a);
	}
	while(m--){
		int k;cin>>k;
		auto it = s.lower_bound(-k);
		if(it!=s.end()){
			cout<<-(*it)<<"\n";
			s.erase(it);
		}else{
			cout<<-1<<"\n";
		}
	}

	return 0;
}
