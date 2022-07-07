#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	double x,y,r;
	cout.precision(2);
	cout<<fixed;
	while(cin>>x>>y>>r){
		if(y+r<=0) {cout<<0.0<<"\n";continue;}
		if(y-r>=0) {cout<<r*r*M_PI<<"\n";continue;}
		double triarea = y*sqrt(r*r-y*y);
		double theta = acos(abs(y)/r);	
		if(y>=0){
			cout<<r*r*(M_PI-theta)+triarea<<"\n";
		}else{
			cout<<r*r*theta+triarea<<"\n";	
		}
	}

	return 0;
}
