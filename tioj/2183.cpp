#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

int n;
vector<pair<int,int> > arr;

bool check(double k,bool type){
	if(type){
		double minv = 1e20;
		for(int i=0;i<n/2;i++) minv = min(minv,(double)arr[i].second-(k*arr[i].first));
		double maxv = -1e20;
		for(int i = n/2;i<n;i++) maxv = max(maxv,(double)(arr[i].second)-(k*arr[i].first));
		return maxv-minv>0;
	}else{
		double maxv = -1e20;
		for(int i=0;i<n/2;i++) maxv = max(maxv,(double)arr[i].second-(k*arr[i].first));
		double minv = 1e20;
		for(int i= n/2;i<n;i++) minv = min(minv,(double)arr[i].second-(k*arr[i].first));
		return minv-maxv>=0;
	}
}

double slope(bool type){
	double l = -1e10;double r = 1e10;
	for(int i=0;i<50;i++){
		double mid = (r+l)/2;
		if(check(mid,type)) l = mid;
		else r = mid;
	}
	return l;
}
pair<int,int> maxpair(){
	double s = slope(1);
	//cerr<<s<<"maxslope\n";
	double minv = 1e20;int minind = -1;
	for(int i=0;i<n/2;i++) {
		if(minv>(double)arr[i].second-(s*arr[i].first)) minind = i;
		minv = min(minv,(double)arr[i].second-(s*arr[i].first));
	}
	double maxv = -1e20;int maxind = -1;
	for(int i = n/2;i<n;i++) {
		if(maxv<(double)(arr[i].second)-(s*arr[i].first)) maxind = i;
		maxv = max(maxv,(double)(arr[i].second)-(s*arr[i].first));
	}
	//cerr<<minind<<" "<<maxind<<"maxpair";
	//double sl = (double)(arr[maxind].second-arr[minind].second)/(double)(arr[maxind].first-arr[minind].first);
	//cerr<<sl<<"\n";
	return {minind,maxind};
}

pair<int,int> minpair(){
	double s = slope(0);
	//cerr<<s<<"minslope\n";
	double minv = 1e20;int minind = -1;
	for(int i=n/2;i<n;i++) {
		if(minv>(double)arr[i].second-(s*arr[i].first)) minind = i;
		minv = min(minv,(double)arr[i].second-(s*arr[i].first));
	}
	double maxv = -1e20;int maxind = -1;
	for(int i = 0;i<n/2;i++) {
		if(maxv<(double)(arr[i].second)-(s*arr[i].first)) maxind = i;
		maxv = max(maxv,(double)(arr[i].second)-(s*arr[i].first));
	}
	//cerr<<maxind<<" "<<minind<<"minpair";
	//double sl = (double)(arr[maxind].second-arr[minind].second)/(double)(arr[maxind].first-arr[minind].first);
	//cerr<<sl<<"\n";
	return {maxind,minind};
}

pair<double,double> inter(pair<int,int> pp1,pair<int,int> pp2){
	pair<double,double> p1 = arr[pp1.first];
	pair<double,double> p2 = arr[pp1.second];
	pair<double,double> p3 = arr[pp2.first];
	pair<double,double> p4 = arr[pp2.second];
	double xt = ((p1.first*p2.second - p1.second*p2.first)*(p3.first-p4.first)) - ((p1.first-p2.first)*(p3.first*p4.second-p3.second*p4.first));
	double yt = ((p1.first*p2.second-p1.second*p2.first)*(p3.second-p4.second))-((p1.second-p2.second)*(p3.first*p4.second-p3.second*p4.first));
	double d = ((p1.first-p2.first)*(p3.second-p4.second))-((p1.second-p2.second)*(p3.first-p4.first));
	return {xt/d,yt/d};
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	arr.resize(n);
	for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;
	sort(arr.begin(),arr.end());
	//for(int i=0;i<n;i++) cout<<arr[i].first<<","<<arr[i].second<<"()\n";
	pair<double,double> ans = inter(maxpair(),minpair());	
	cout<<fixed<<setprecision(2)<<ans.first<<" "<<ans.second;
	return 0;
}
// binary search for max slope and min slope and find the intersection
