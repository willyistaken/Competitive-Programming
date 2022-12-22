#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


double pow(double a,int p){
	double r = 1.0;
	while(p){
		if(p&1) r = r*a;
		a = a*a;
		p>>=1;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	double ans = (double)k;
	for(int i=1;i<k;i++){
		ans-=pow((double(i))/(double)k,n);
	}
	cout<<fixed<<setprecision(6)<<ans<<"\n";
	return 0;
}
