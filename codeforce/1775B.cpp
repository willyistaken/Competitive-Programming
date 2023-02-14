#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vector<vector<int> > arr(n);
		map<int,int> cnt;
		for(int i=0;i<n;i++){
			int k;cin>>k;
			arr[i].resize(k);
			for(int j=0;j<k;j++){
				cin>>arr[i][j];
				cnt[arr[i][j]]++;
			}
		}
		bool yes= 0;
		for(int i=0;i<n;i++){
			bool works = 1;
			for(auto k : arr[i]){
				if(cnt[k]==1){
					works=0;
					break;
				}
			}
			if(works){
				yes=1;
				cout<<"Yes\n";
				break;
			}
		}
		if(!yes) cout<<"No\n";
	}

	return 0;
}
