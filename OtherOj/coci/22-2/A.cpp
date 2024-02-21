#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define int ll



signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<int> d(n);
	d[0]=0;
	for(int i=1;i<n;i++){
		string s;cin>>s;
		if(s[0]=='P'){
			int a;cin>>a;
			d[i]=a;
		}else{
			int y,a;cin>>y>>a;
			d[i] = d[y-1]+a;
		}
	}
	pair<int,int> minn = {1e15,-1};
	for(int i=1;i<n;i++){
		minn = min(make_pair(d[i]-d[i-1],i),minn);
	}
	cout<<minn.first<<" "<<minn.second<<" "<<minn.second+1<<"\n";
	
	

	return 0;
}
