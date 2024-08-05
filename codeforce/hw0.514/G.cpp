#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,p;cin>>n>>p;
	vector<int> a(n);
	vector<int> b(n);
	ll Asum = 0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		Asum+=a[i];
	}
	if(Asum<=p){
		cout<<-1<<"\n";
		return 0;
	}
	double l = 0;double r = 1e12;
	for(int _=0;_<1000;_++){
		double m = (l+r)/2;
		double need = 0;
		for(int i=0;i<n;i++){
			need+=max(0.0,((a[i]*m)-(double)b[i]));
		}
		if(need<=m*p) l = m;
		else r = m;
	}
	cout<<setprecision(6)<<fixed<<l<<"\n";
	
	return 0;
}
