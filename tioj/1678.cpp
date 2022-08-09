#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

struct pt{
	ll x;
	ll y;
};

pt operator-(const pt &a,const pt &b){
	pt result;
	result.x = a.x-b.x;
	result.y = a.y-b.y;
	return result;
}

ll operator^(const pt &a,const pt &b){
	return a.x*b.y-a.y*b.x;
}

ll operator*(const pt &a,const pt &b){
	return a.x*b.x+a.y*b.y;
}

ll darea(vector<pt> &s){
	int _n = s.size();
	ll ans=0;
	for(int i=0;i<_n-1;i++){
		ans +=	 s[i]^s[i+1];
	}
	ans+=s[_n-1]^s[0];
	if(ans<0) ans = -ans;
	return ans;
}

int main(){
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a;
	scanf("%d %d",&n,&a);
	vector<pt> arr(n);
	for(int i=0;i<n;i++) scanf("%ld %ld",&arr[i].x,&arr[i].y);
	ll ogarea = darea(arr);
	sort(arr.begin(),arr.end(),[](const pt &a,const pt &b){return (a.x==b.x)?(a.y<b.y):(a.x<b.x);});	
	vector<pt> convex;	
	convex.push_back(arr[0]);
	for(int i=1;i<n;i++){
		while(convex.size()>=2){
			if(((convex[convex.size()-1]-convex[convex.size()-2])^(arr[i]-convex[convex.size()-2]))<0) break;
			convex.pop_back();
		}
		convex.push_back(arr[i]);
	}
	int g = convex.size()-1;
	for(int i=n-2;i>=0;i--){
		while(convex.size()-g>=2){
			if(((convex[convex.size()-1]-convex[convex.size()-2])^(arr[i]-convex[convex.size()-2]))<0) break;
			convex.pop_back();
		}
		convex.push_back(arr[i]);
	}
	convex.pop_back();

	/*
	cout<<"\n";
	for(auto i : convex) cout<<i.x<<" "<<i.y<<"\n";
	cout<<"\n";
	*/		

	ll convexarea = darea(convex);
	/*
	cout<<convexarea<<"\n";
	cout<<ogarea<<"\n";
	*/
	ll leftover = convexarea-ogarea;
	leftover = (leftover%2) + (leftover/2);
	ll ans = (leftover/a) + ((leftover%a)!=0);
	printf("%ld\n",ans);
	return 0;
}
