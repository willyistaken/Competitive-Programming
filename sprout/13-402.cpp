#include<bits/stdc++.h>
using namespace std;
#define ll long long



struct vec{
	double	x;
	double y;
};

const double eps = 1e-3;
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
	int t;scanf("%d",&t);
	int n;
	while(t--){
		scanf("%d",&n);
		vec arr[n];
		for(int i=0;i<n;i++){
			scanf("%lf  %lf",&arr[i].x,&arr[i].y);
		}
	sort(arr,arr+n,[](const vec &a,const vec &b){return (a.x<b.x || (a.x==b.x && a.y<b.y));});		
	vector<int> convexhull;
	for(int i=0;i<n;i++){
		while(convexhull.size()>=2){
			if(sign((arr[convexhull[convexhull.size()-1]]-arr[convexhull[convexhull.size()-2]])^(arr[i]-arr[convexhull[convexhull.size()-1]]))>0){
				break;	
			}
			convexhull.pop_back();
		}
		convexhull.push_back(i);
	}
	convexhull.pop_back();	
	int s = convexhull.size();
	for(int i=n-1;i>=0;i--){
		while(convexhull.size()-s>=2){
			if(sign((arr[convexhull[convexhull.size()-1]]-arr[convexhull[convexhull.size()-2]])^(arr[i]-arr[convexhull[convexhull.size()-1]]))>0){
				break;	
			}
			convexhull.pop_back();
		}
		convexhull.push_back(i);
	}
	double sum=0;
	//cout<<convexhull[0]<<" ";
	for(int i=0;i<convexhull.size()-1;i++){
		sum += (arr[convexhull[i]]^arr[convexhull[i+1]]	)/2;
	}
	printf("%.1lf\n",fabs(sum));
	}

	return 0;
}

