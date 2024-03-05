#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,t;cin>>n>>t;	
	map<ll,int> mp;
	vector<ll> score(n+1,0);
	mp[0]+=n;
	for(int i=1;i<=t;i++){
		int ind,v;cin>>ind>>v;
		mp[score[ind]]--;
		if(mp[score[ind]]==0){
			mp.erase(score[ind]);
		}
		score[ind]+=v;
		mp[score[ind]]++;
		cout<<mp.size()<<"\n";
	}

	return 0;
}
