#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int s,t,n;
int discount(int x){
	if(x*5<=t) return 7;
	if(x*5<=2*t) return 8;
	if(x*5<=3*t) return 9;
	return 10;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s>>t>>n;
	int all=0;
	for(int i=0;i<n;i++) {
		int k;cin>>k;
		all+=k;
	}
	double sum=0;
	for(int i=1;i<=all;i++){
		sum+= (double)s*((double)discount(i)/10);
	}
	cout<<(int)(((sum)-(0.3*(double)s*(double)t))+(((sum)>=(0.3*(double)s*(double)t))?(0.5):(-0.5)))<<"\n";
	return 0;
}
