#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<int> arr(n);
	vector<int> d(n);
	for(int i=0;i<n;i++){cin>>arr[i];d[i]=arr[i];}
	sort(d.begin(),d.end())	;
	d.resize(unique(d.begin(),d.end())-d.begin());
	vector<int> maxloc(d.size(),-1);
	for(int i=0;i<n;i++){
		int p = lower_bound(d.begin(),d.end(),arr[i])-d.begin();
		maxloc[p] = max(i,maxloc[p]);
	}
	int tobe=-1;
	int cur = 0;
	for(int i=0;i<n;i++){
		if(i>tobe){
			cur = lower_bound(d.begin(),d.end(),arr[i])-d.begin();
			tobe = maxloc[cur];
		}
		cout<<d[cur]<<"\n";
	}

	return 0;
}
