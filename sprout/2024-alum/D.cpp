#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct vec{
	ll x;
	ll y;
};

ll operator^(const vec &a,const vec &b){
	return a.x*b.y-a.y*b.x;
}
vec operator-(const vec &a,const vec &b){
	return {a.x-b.x,a.y-b.y};
}


void get(vector<vec> arr){
	int n = arr.size();
	sort(arr.begin(),arr.end(),[](const vec &a,const vec &b){return (a.x<b.x || (a.x==b.x && a.y<b.y));});
	vector<int> convex;
	
	for(int i=0;i<n;i++){
		while(convex.size()>=2){
			if(((arr[convex[convex.size()-1]]-arr[convex[convex.size()-2]])^(arr[i]-arr[convex[convex.size()-1]]))>0) break;	
			convex.pop_back();
		}
		convex.push_back(i);
	}
	convex.pop_back();
	int s = convex.size();
	for(int i=n-1;i>=0;i--){
		while(convex.size()-s>=2){
			if(((arr[convex[convex.size()-1]]-arr[convex[convex.size()-2]])^(arr[i]-arr[convex[convex.size()-1]]))>0) break;	
			convex.pop_back();
		}
		convex.push_back(i);
	}
	ll sum=0;
	for(int i=0;i<convex.size()-1;i++){
		sum+= arr[convex[i]]^arr[convex[i+1]];

	}
	cout<<sum<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<vec> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i].x>>arr[i].y;	
	}
	for(int i=0;i<n;i++){
		vector<vec> g;
		for(int j=0;j<n;j++){
			if(i==j) continue;
			g.push_back(arr[i]);
		}
		get(g);
	}


	return 0;
}

