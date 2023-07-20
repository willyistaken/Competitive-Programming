#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define int ll
struct square{
	int x;int y;
	int xp;int yp;
};


signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	vector<ll> blackunion(n+1,0);
	vector<square> s(k);
	ll blacksum = 0;
	for(int i=0;i<k;i++){
		cin>>s[i].x>>s[i].xp>>s[i].y>>s[i].yp;
		s[i].x--;
		s[i].y--;
		s[i].xp--;
		s[i].yp--;
		blacksum+=1LL*(s[i].y-s[i].x+1)*(s[i].yp-s[i].xp+1);
	}
	ll minn = LONG_LONG_MAX;
	for(int d=1;d<n;d++){
		if(n%d) continue;
		for(int i=0;i<k;i++){
			ll hoz = 0;
			ll ver = 0;
			int g = (s[i].y/d)-(s[i].x/d);
			if(g==0) hoz = s[i].y-s[i].x+1;
			else{
				if(g&1){
					hoz = (d*(g/2))+d-(s[i].x%d);
				}else{
					hoz = d-(s[i].x%d)+(s[i].y%d)+1+(d*((g-1)/2));
				}
			}
			int h = (s[i].yp/d)-(s[i].xp/d);
			if(h==0) ver = s[i].yp-s[i].xp+1;
			else{
				if(h&1){
					ver = (d*(h/2))+d-(s[i].xp%d);
				}else{
					ver = d-(s[i].xp%d)+(s[i].yp%d)+1+(d*((h-1)/2));
				}
			}
			//cout<<ver<<" "<<hoz<<"\n";
			ll block = (ver*hoz)+(s[i].y-s[i].x+1-hoz)*(s[i].yp-s[i].xp+1-ver);
			if((((s[i].x/d)&1)^((s[i].xp/d)&1))==0) blackunion[d]+=block;	
			else blackunion[d]+=1LL*(s[i].y-s[i].x+1)*(s[i].yp-s[i].xp+1)-block;
		}
		ll allblack = 0;
		if((n/d)&1) allblack= 1LL*d*d*(1LL*(n/d)*(((n/d)/2))+((n/d)/2+1));
		else allblack = 1LL*d*d*(1LL*(n/d)*(n/d)/2);
		//cout<<d<<" "<<blackunion[d]<<" "<<allblack<<" "<<blacksum<<"\n";
		minn = min(minn,blacksum+allblack-2*blackunion[d]);
		minn = min(minn,2*blackunion[d]+(1LL*n*n-allblack)-blacksum);
	}
	cout<<minn<<"\n";
	return 0;
}
