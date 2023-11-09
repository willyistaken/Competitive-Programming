#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 2e5+4;
int arrr[200005];

void add(int x,int v){
	while(x<=N){
		arrr[x]+=v;
		x+=(x&-x);
	}
}
int qry(int x){
	int ans= 0 ;
	while(x){
		ans+=arrr[x]	;
		x-=(x&-x);
	}
	return ans;
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,d,w;cin>>n>>d>>w;
	vector<pair<int,int> > arr(n);
	vector<pair<pair<int,int>,int> > query;
	for(int i=0;i<n;i++){
		cin>>arr[i].first>>arr[i].second;
		query.push_back({make_pair(arr[i].first,arr[i].first+w-1),arr[i].second});
		query.push_back({make_pair(arr[i].first,arr[i].first+w-1),arr[i].second+d-1});
		query.push_back({make_pair(arr[i].first-w+1,arr[i].first),arr[i].second});
		query.push_back({make_pair(arr[i].first-w+1,arr[i].first),arr[i].second+d-1});
	}
	sort(arr.begin(),arr.end(),[](pair<int,int> a,pair<int,int> b){return a.second<b.second;});
	sort(query.begin(),query.end(),[](pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){return a.second<b.second;});
	int al = 0;
	int ar = 0;
	int head = 0;
	int ans = 0;
	for(int t=0;t<=2e5;t++){
		while(ar<n && arr[ar].second<=t) add(arr[ar++].first,1);
		while(al<n && arr[al].second<=t-d) add(arr[al++].first,-1);
		while(head<query.size() && query[head].second==t){
			int l = max(0,query[head].first.first-1);
			int r = min(200004,query[head].first.second);
			//cout<<l<<" "<<r<<" "<<t<<"\n";
			ans = max(ans,qry(r)-qry(l));	
			head++;
		}
		while(head<query.size() && query[head].second<=t){
			head++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
