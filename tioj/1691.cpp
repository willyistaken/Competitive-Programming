#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	unordered_map<int,int> place;
	int mingap=INT_MAX;
	for(int i=0;i<n;i++){
		int k;cin>>k;
		if(place.count(k)) mingap = min(mingap,i-place[k]);
		place[k]=i;
	}
	if(place.size()==n) {
		cout<<0<<"\n";
	}else{
		cout<<n-mingap<<"\n";
	}
	return 0;
}
