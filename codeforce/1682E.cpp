#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


map<pair<int,int>,int> exist;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;	
	int arr[n+1];
	for(int i=1;i<=n;i++) cin>>arr[i];
	queue<pair<int,int>  > tobe;
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		if(a>b) swap(a,b);
		exist.insert(make_pair(make_pair(a,b),i+1));
		if(arr[a]==b || arr[b]==a){
			tobe.push(make_pair(a,b));
		}
	}
	while(tobe.size()){
			pair<int,int> tsw = tobe.front();
			tobe.pop();
			cout<<exist[tsw]<<" ";
			exist.erase(tsw);
			swap(arr[tsw.first],arr[tsw.second]);
			if(exist.count(make_pair(min(tsw.first,arr[tsw.first]),max(tsw.first,arr[tsw.first])))) tobe.push(make_pair(min(tsw.first,arr[tsw.first]),max(tsw.first,arr[tsw.first])));
			if(exist.count(make_pair(min(tsw.second,arr[tsw.second]),max(tsw.second,arr[tsw.second])))) tobe.push(make_pair(min(tsw.second,arr[tsw.second]),max(tsw.second,arr[tsw.second])));
	}


	return 0;
}
