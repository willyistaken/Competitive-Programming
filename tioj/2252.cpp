#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point{
	ll x;
	ll y;
};


double operator>>(const point &a,const point &b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

ll operator^(const point &a,const point &b){
	return a.x*b.y - a.y*b.x;
}

ll operator*(const point &a,const point &b){
	return a.x*b.x+a.y*b.y;
}
point operator-(const point &a,const point &b){
	return	{a.x-b.x,a.y-b.y};
}

double disofseg(point be,point ed,point g){
	if((ed-be)*(g-be)<0 || (be-ed)*(g-ed)<0){
		return min(g>>be,g>>ed);
	}else{
		double area = (double)abs((ed-be)^(g-be));
		return area/(be>>ed);
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	point s;int n;cin>>s.x>>s.y>>n;
	n++;
	point arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].x>>arr[i].y;	
	}
	double ans=1e7;
	for(int i=0;i<n-1;i++){
		ans = min(ans,disofseg(arr[i],arr[i+1],s));	
	}
	cout<<setprecision(12)<<fixed<<ans<<"\n";



	return 0;
}
