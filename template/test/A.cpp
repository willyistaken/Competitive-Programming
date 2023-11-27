#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int n; cin>>n;
	vector<int> arr(n);
	pair<int,int> maxabs = {0,-1};
	for(int i=0;i<n;i++) cin>>arr[i];
	int pcnt = 0;
	int ncnt = 0;
	for(int i=0;i<n;i++){
		maxabs = max(maxabs,{abs(arr[i]),i});
		if(arr[i]>0) pcnt++;
		if(arr[i]<0) ncnt++;
	}
	bool norp = 0;
	vector<pair<int,int> > ans;
	if(arr[maxabs.second]<0){
		if(pcnt>12){
			norp=1;	
			int ff = -1;
			for(int i=0;i<n;i++) if(arr[i]>0) ff=i;
			for(int g = 0;g<5;g++) ans.push_back({ff,ff});
			for(int i=0;i<n;i++){
				if(arr[i]<0) ans.push_back({ff,i});
			}
		}else{
			norp=0;	
			for(int i=0;i<n;i++){
				if(arr[i]>0) ans.push_back({i,maxabs.second});
			}
		}
	}else{
		if(ncnt>12)	{
			norp=0;	
			int ff = -1;
			for(int i=0;i<n;i++) if(arr[i]<0) ff=i;
			for(int g=0;g<5;g++) ans.push_back({ff,ff});
			for(int i=0;i<n;i++){
				if(arr[i]>0) ans.push_back({ff,i});
			}
		}else{
			norp=1;
			for(int i=0;i<n;i++){
				if(arr[i]<0) ans.push_back({i,maxabs.second});
			}
		}
	}
	assert(ans.size()+(n-1)<=31);
	cout<<ans.size()+(n-1)<<"\n";
	for(auto i : ans) cout<<i.first+1<<" "<<i.second+1<<"\n";
	if(norp){
		for(int i=1;i<n;i++) cout<<i+1<<" "<<i<<"\n";
	}else{
		for(int i=n;i>1;i--) cout<<i-1<<" "<<i<<"\n";
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t=1;
	while(t--){
		solve();
	}

	return 0;
}

