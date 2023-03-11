#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct p{
	double x;
	double y;
};
int n;
p arr[100000];	

bool check(double d){
	double l = 0;
	double r = 0;
	bool hasstuff = 0;
	for(int i=0;i<n;i++){
		if(arr[i].y>2*d) return 0;
		double len = (d*d)-((arr[i].y-d)*(arr[i].y-d));
		len = sqrt(len);
		l = (hasstuff)?(max(l,arr[i].x-len)):(arr[i].x-len);
		r = (hasstuff)?(min(r,arr[i].x+len)):(arr[i].x+len);
		hasstuff = 1;
	}
	return (r>=l);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i].x>>arr[i].y;				
	}
	bool pos = (arr[0].y>0);
	arr[0].y = abs(arr[0].y);
	for(int i=1;i<n;i++){
		if(pos^(arr[i].y>0)){
			cout<<-1<<"\n";
			return 0;
		}
		arr[i].y = abs(arr[i].y);
	}
	double r = 1e16;	
	double l = 0;
	for(int i=0;i<150;i++){
		double mid = (l+r)/2;
		if(check(mid)) r = mid;
		else l = mid;
	}
	cout<<fixed;
	cout<<r<<"\n";
	return 0;
}
