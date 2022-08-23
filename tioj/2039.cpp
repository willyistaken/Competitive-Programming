#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
int n,k;
vector<int> a;

struct alien{
	ll f;
	int k;
};

alien cmax(const alien &a,const alien &b){
	if(a.f==b.f){
		if(a.k<b.k) return a;
		else return b;
	}else{
		if(a.f<b.f) return b;
		else return a;
	}
}

alien deal(int p){
	alien dp0 = {0,0};
	alien dp1 = {-a[0],0};
	for(int i=1;i<n;i++){
		alien temp = dp0;
		dp0 = cmax(dp0,{dp1.f+a[i]-p,dp1.k+1});
		dp1 = cmax(dp1,{temp.f-a[i],temp.k});
	}
	return dp0;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	a.resize(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int l=-1;int r=10000001;
	while(r-l>1){
		int mid = (r+l)/2;
		alien temp = deal(mid);
		if(temp.k>k) l = mid;
		else r = mid;
	}
	cout<<deal(r).f+r*k<<"\n";
	
	return 0;
}
