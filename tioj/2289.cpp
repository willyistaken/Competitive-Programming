#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<int> choose;

bool check(int v){
	 return lower_bound(choose.begin(),choose.end(),v)!=choose.end();
}

struct range{
	int l,r;
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	vector<range> arr;		
	for(int i=0;i<q;i++){
		int a,b;cin>>a>>b;
		arr.push_back({a,b});
	}
	int ans = 0;
	sort(arr.begin(),arr.end(),[](const range &a,const range &b){return a.r<b.r;});
	for(int i=0;i<q;i++){
		if(!check(arr[i].l)){
			choose.push_back(arr[i].r);
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
