#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


struct v{
	ll x;
	ll y;
};

ll operator^(const v&a,const v&b){
	return a.x*b.y-a.y*b.x;
}

v operator-(const v&a,const v&b){
	v r = {a.x-b.x,a.y-b.y};
	return r;
}

ll operator*(const v&a,const v&b){
	return a.x*b.x+a.y*b.y;
}

int ty(ll a){
	if(a==0) return 0;
	if(a>0) return 1;
	return 2;
}

bool on(v p1,v p2,v p3){
	if(((p2-p1)^(p3-p1))!=0) return 0;
	return (((p3-p1)*(p3-p2))<=0);
}

bool inter(v p1,v p2,v p3,v p4){
		if(on(p1,p2,p3) || on(p1,p2,p4) || on(p3,p4,p1) ||on(p3,p4,p2) ){
			return 1;
		}
		return (ty((p2-p1)^(p3-p1))!=ty((p2-p1)^(p4-p1)) && ty((p4-p3)^(p1-p3))!=ty((p4-p3)^(p2-p3)));
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	v arr[n];	
	for(int i=0;i<n;i++) cin>>arr[i].x>>arr[i].y;
	v p;
	v inf;
	inf.x = 0;
	inf.y = 1e9+50;
	for(int i=0;i<m;i++){
		cin>>p.x>>p.y;
		bool boun = 0;
		for(int i=0;i<n;i++){
			if(on(arr[i],arr[(i+1)%n],p)){
				boun = 1;
				break;
			}
		}
		if(boun){
			cout<<"BOUNDARY\n";
			continue;
		}
		bool works = 0;
		for(int i=0;i<n;i++){
			if(inter(arr[i],arr[(i+1)%n],p,inf)) works^=1;
		}
		if(works) cout<<"INSIDE\n";
		else cout<<"OUTSIDE\n";
	}
	return 0;
}
