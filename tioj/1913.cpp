#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
int n;
struct spt{
	vector<vector<pair<int,int> > > arr;
	void init(){
		arr.resize(14);
		for(int i=0;i<14;i++){
			arr[i].resize(n);
			fill(arr[i].begin(),arr[i].end(),make_pair(0,0));
		}
	}
	void build(){
		for(int j=1;j<14;j++){
			for(int i=0;i+(1<<(j-1))<n;i++){
				arr[j][i].first = max(arr[j-1][i].first,arr[j-1][i+(1<<(j-1))].first);	
				arr[j][i].second = min(arr[j-1][i].second,arr[j-1][i+(1<<(j-1))].second);	
			}
		}
	}
	pair<int,int> query(int l,int r){
		if(l>r) swap(l,r);
		r++;
		int p = __lg(r-l);
		pair<int,int> result;
		result.first = max(arr[p][l].first,arr[p][r-(1<<p)].first);
		result.second = min(arr[p][l].second,arr[p][r-(1<<p)].second);
		return result;
	}

};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		spt seg;
		seg.init();
		int ind[n+1];
		for(int i=0;i<n;i++){
			int k;cin>>k;
			ind[k]=i;
			seg.arr[0][i] = make_pair(k,k);
		}
		seg.build();
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				pair<int,int> temp = seg.query(ind[i],ind[j]);
				if(temp.first ==j && temp.second ==i && abs(ind[i]-ind[j])==j-i) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

// condition:
/*
max(ai,bi) = max(a,b);
min(ai,bi) = min(a,b);
max(ai,bi)-min(ai,bi) = (b-a)

in n^2log(n);
can be optimize to n^2
use sparsetable

*/
