#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<long double> a;
vector<long double> b;
int n,l;
bool check(long double g){
	long double minn = 1e20;	
	for(int i=1;i<=n;i++){
		if(i>=l){
			minn = min(minn,a[i-l]-(g*b[i-l]));	
			if(a[i]-(g*b[i])>=minn) return 1;
		}
	}
	return 0;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>l;	
	a.resize(n+1);
	b.resize(n+1);
	a[0]=0;
	b[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
	}

	for(int i=1;i<=n;i++){
		cin>>b[i];
		b[i]+=b[i-1];
	}
	long double l = 0; long double r = 2e10+5;
	for(int i=0;i<=50;i++){
		long double mid = (r+l)/2;
		cout<<fixed;
		if(check(mid)) l = mid;
		else r = mid;
	}
	cout<<l<<"\n";
	return 0;
}
