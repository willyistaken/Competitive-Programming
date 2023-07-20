#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

bool issquare(ll a){
	ll l=0;
	ll r = 1e9+5;
	while(r-l>1){
		ll mid = (l+r)/2;
		if(mid*mid<=a) l = mid;
		else r= mid;
	}
	if(l*l==a) return 1;
	else return 0;
}



void solve(){
	int n;cin>>n;
	set<double > rq;
	set<double> ri;
	set<pair<double,double> > cq;
	set<pair<double,double> > ci;
	for(int i=0;i<n;i++){
	ll a,b,c;cin>>a>>b>>c;
	if(a==0){
		if(b){
			rq.insert((double)-c/b);
		}
	}
	if(b*b<4*a*c){
					
	}else{
		double k = sqrt((double)(b*b-4*a*c));
		if(issquare(b*b-4*a*c)){
			
		}else{
			double r = (-(double)b+k)/(2*(double)a);
			ri.insert(")
		}
	}
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
