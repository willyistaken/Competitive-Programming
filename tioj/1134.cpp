#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;

int ones[205][205];
int zeros[205][205];

int maxarea(int l,int r){
	vector<pair<int,int> > arr;
	int onesum=0;
	int zerosum=0;
	for(int i=0;i<=n;i++){
		onesum += ones[i][r]-ones[i][l];
		zerosum += zeros[i][r]-zeros[i][l];
		arr.push_back(make_pair(onesum-zerosum,-i));
	}
	sort(arr.begin(),arr.end());
	int maxl= 0;
	int minb = -arr[0].second;
	for(int i=1;i<=n;i++){
		pair<int,int> temp = arr[i];
		if(minb<-temp.second){
			maxl = max(maxl,-temp.second-minb);
		}else{
			minb = -temp.second;
		}
	}
	return maxl*(r-l);
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>m;
		memset(ones,0,sizeof(ones));
		memset(zeros,0,sizeof(zeros));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				int b;cin>>b;
				ones[i][j] = ones[i][j-1]+!b;
				zeros[i][j] = zeros[i][j-1]+b;
			}
		}
		int ans=0;
		for(int l=0;l<m;l++){
			for(int r=l+1;r<=m;r++){
				ans = max(ans,maxarea(l,r));	
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
