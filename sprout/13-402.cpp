#include<bits/stdc++.h>
using namespace std;
#define ll long long



struct vec{
	double	x;
	double y;
};

const double eps = 1e-5;
int sign(double a){
	if(fabs(a)<=eps) return 0;
	return (a>0) ? 1:-1;
}
double operator*(const vec &a,const vec &b){
	return a.x*b.x + a.y*b.y;
}
double operator^(const vec &a,const vec &b){
	return a.x*b.y - a.y*b.x;
}
vec operator-(const vec &a,const vec &b){
	return {a.x-b.x,a.y-b.y};
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vec arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i].x>>arr[i].y;	
		}
	sort(arr,arr+n,[](const vec &a,const vec &b){return (a.x<b.x || (a.x==b.x && a.y>b.y));});		
	deque<int> down;
	down.push_back(0);
	for(int i=1;i<n;i++){
		while(down.size()>1){
			if(sign((arr[down[down.size()-1]]-arr[down[down.size()-2]])^(arr[i]-arr[down[down.size()-1]]))<=0){
				break;	
			}
			down.pop_back();
		}
		down.push_back(i);
	}
	deque<int> up;
	up.push_back(n-1);
	for(int i=n-2;i>=0;i--){
		while(up.size()>1){
			if(sign((arr[up[up.size()-1]]-arr[up[up.size()-2]])^(arr[i]-arr[up[up.size()-1]]))<=0){
				break;	
			}
			up.pop_back();
		}
		up.push_back(i);
	}
	double sum=0;
	for(int i=1;i<down.size();i++){
		sum+=arr[down[i]]^arr[down[i-1]];	
	}
	for(int i=1;i<up.size();i++){
		sum +=arr[up[i]]^arr[up[i-1]];
	}
	cout<<setprecision(1)<<fixed<<sum/2<<endl;
	}

	return 0;
}

