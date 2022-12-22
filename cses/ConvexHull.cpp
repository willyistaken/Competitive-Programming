#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct p{
	ll x;
	ll y;
};

ll operator^(const p&a,const p&b){
	return a.x*b.y-a.y*b.x;
}

p operator-(const p&a,const p&b){
	p r = {a.x-b.x,a.y-b.y};
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;	
	vector<p> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i].x>>arr[i].y;
	sort(arr.begin(),arr.end(),[](const p&a,const p&b){return (a.x==b.x)?(a.y<b.y):(a.x<b.x);});
	vector<int> cxhu;
	for(int i=0;i<n;i++){
		int s;
		while((s=cxhu.size())>=2 && ((arr[i]-arr[cxhu[s-2]])^(arr[cxhu[s-1]]-arr[cxhu[s-2]]))>0){
			cxhu.pop_back();	
		}
		cxhu.push_back(i);
	}
	vector<int> cxhd;
	for(int i=n-1;i>=0;i--){
		int s;
		while((s=cxhd.size())>=2 && ((arr[i]-arr[cxhd[s-2]])^(arr[cxhd[s-1]]-arr[cxhd[s-2]]))>0){
			cxhd.pop_back();	
		}
		cxhd.push_back(i);
	}
	set<int> s;
	for(auto i : cxhu) s.insert(i);
	for(auto i : cxhd) s.insert(i);
	cout<<s.size()<<"\n";
	for(auto i : s){
		cout<<arr[i].x<<" "<<arr[i].y<<"\n";
	}
	return 0;
}
