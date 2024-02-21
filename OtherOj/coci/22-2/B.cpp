#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct op{
	char R1,R2,R3;
};
char G[2] = {'A','B'};
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll x,y;cin>>x>>y;
	bool k = (x<y);
	if(x<y) swap(x,y);
	vector<op> ans;
	while(y){
		if(y&1) ans.push_back({G[k],'C','C'});
		y>>=1;
		if(y) ans.push_back({G[k],G[k],G[k]});
	}
	assert(ans.size()<=100);
	cout<<ans.size()<<"\n";
	for(auto i : ans){
		cout<<i.R1<<" "<<i.R2<<" "<<i.R3<<"\n";
	}
	cout<<"C\n";

	return 0;
}
