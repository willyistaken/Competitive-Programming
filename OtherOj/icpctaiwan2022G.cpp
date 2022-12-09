#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<int> a;
vector<int> b;
int n;
int get(int l,int r,int m){
	priority_queue<pair<int,int> > pq;	
	for(int i = 0;i<=r;i++){
		pq.push({a[i],i});
	}
	for(int i = 1;i<=l;i++){
		pq.push({a[n-i],n-i});
	}
	int ans = 0;
	for(int i=0;i<m && pq.size() ;i++){
		ans+=pq.top().first;
		int v = pq.top().first-b[pq.top().second];
		if(v>0) pq.push({v,pq.top().second});
		pq.pop();
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	int t;cin>>t;
	a.resize(n);
	b.resize(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	int ans = 0;
	for(int k=0;k<n;k++){
		for(int g = 0;g<k/4+1;g++){
			int r = g;
			int l = k-2*g;
			ans = max(ans,get(l,r,t-k));
		}
		for(int g=0;g<k/4+1;g++){
			int r = k-2*g;
			int l = g;
			ans = max(ans,get(l,r,t-k));
		}
	}
	cout<<ans<<"\n";
	return 0;
}
