#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	pair<int,int> range[n];
	for(int i=1;i<=2*n;i++){
		int a;cin>>a;
		a--;	
		if(range[a].first) range[a].second = i;
		else range[a].first = i;
	}
	sort(range,range+n,[](pair<int,int> a,pair<int,int> b){return (a.second==b.second)?(a.first<b.first):(a.second<b.second);});
	pair<int,int> last = {0,0};
	int ans = 0;
	for(int i=0;i<n;i++){
		int l = range[i].first;
		int r = range[i].second;
		if(l<=last.second) continue;
		else if(l<=last.first){
			last.second = last.first;
			last.first = r;
		}else{
			last.first = r;
		}
		ans++;
	}
	cout<<ans<<"\n";
	return 0;
}
