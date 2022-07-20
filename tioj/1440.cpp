#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int need[n];
	for(int i=0;i<n;i++) cin>>need[i];
	int m;cin>>m;
	pair<int,int> breakfast[m];
	for(int i=0;i<m;i++) cin>>breakfast[i].first>>breakfast[i].second;
	sort(need,need+n);sort(breakfast,breakfast+m);
	ll sum=0;
	int nhead=0;
	for(int i=0;i<m && nhead<n;i++){
		if(breakfast[i].first>=need[nhead]){
			sum+=breakfast[i].second;
			nhead++;
		}
	}
	if(nhead<n) cout<<"Impossible.\n";
	else cout<<sum<<"\n";
	return 0;

	return 0;
}
