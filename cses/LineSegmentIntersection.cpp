#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct v{
	ll x;
	ll y;
};

v operator-(const v &a,const v &b){
	v r= {a.x-b.x,a.y-b.y};
	return r;
}

ll operator^(const v &a,const v &b){
	return (a.x*b.y-a.y*b.x);
}

ll operator*(const v&a,const v&b){
	return (a.x*b.x+a.y*b.y);
}

int ty(const v &a,const v &b){
	if((a^b)>0) return 0;
	if((a^b)==0) return 1;
	return 3;
}

bool on(v p1,v p2,v p3){
	if(ty(p2-p1,p3-p1)!=1) return 0;
	return ((p3-p1)*(p3-p2)<=0);
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		v p1,p2,p3,p4;
		cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y>>p4.x>>p4.y;
		if(on(p1,p2,p3) || on(p1,p2,p4) || on(p3,p4,p1) ||on(p3,p4,p2)){
			cout<<"YES\n";
			continue;
		}
		if(ty(p2-p1,p3-p1)!=ty(p2-p1,p4-p1) && ty(p4-p3,p1-p3)!=ty(p4-p3,p2-p3)){
			cout<<"YES\n";
			continue;
		}
		cout<<"NO\n";
	}
	return 0;
}
