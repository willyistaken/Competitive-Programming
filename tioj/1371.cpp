#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

struct pt{
	ll x;
	ll y;
	int number=0;
};

bool operator^(const pt &a,const pt &b){
	return a.x*b.y<a.y*b.x;
}

pt operator-(const pt &a,const pt &b){
	pt r;r.x = a.x-b.x;r.y = a.y-b.y;
	return r;
}

bool works(const pt &a,const pt &b,const pt &c){
	return ((a-c)^(b-c));
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<pt> arr(n);
	for(int i=0;i<n;i++) {
		cin>>arr[i].x>>arr[i].y;
		arr[i].number=i+1;
	}
	if(n==1){
		cout<<"1\n1\n";
		return 0;
	}
	sort(arr.begin(),arr.end(),[](const pt &a,const pt &b){return (a.x==b.x)?(a.y<b.y):(a.x<b.x);});

	vector<pt> convex;
	int g = convex.size();
	for(int i=0;i<n;i++){
		while(convex.size()-g>=2){
			if(works(arr[i],convex[convex.size()-1],convex[convex.size()-2])) break;
			convex.pop_back();
		}
		convex.push_back(arr[i]);
	}
	convex.pop_back();

	g = convex.size();
	for(int i=n-1;i>=0;i--){
		while(convex.size()-g>=2){
			if(works(arr[i],convex[convex.size()-1],convex[convex.size()-2])) break;
			convex.pop_back();
		}
		convex.push_back(arr[i]);
	}
	convex.pop_back();
	sort(convex.begin(),convex.end(),[](const pt &a,const pt &b){return a.number<b.number;});
	cout<<convex.size()<<"\n";
	for(auto i : convex) cout<<i.number<<"\n";
	return 0;
}
// there exist a test data n=1..... 
