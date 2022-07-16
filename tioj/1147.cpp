#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	pair<int,int> city[n];
	for(int i=0;i<n;i++) cin>>city[i].first>>city[i].second;
	sort(city,city+n);
	ll mindis=LONG_LONG_MAX;
	int which=0;
	for(int i=0;i<n;i++){
		ll dis=0;		
		for(int j=0;j<n;j++){
			dis+=abs(city[i].first-city[j].first);
			dis+=abs(city[i].second-city[j].second);
		}
		if(dis<mindis){
			which = i;
			mindis=dis;
		}
	}
	cout<<city[which].first<<" "<<city[which].second<<"\n";
	cout<<mindis<<"\n";
	return 0;
}
