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

int cnt(v p1,v p2){
	if(p1.x==p2.x || p1.y==p2.y){
		return max(abs(p1.x-p2.x),abs(p1.y-p2.y))+1;
	}
	int dx = abs(p1.x-p2.x);
	int dy = abs(p1.y-p2.y);
	int r = __gcd(dx,dy);
	return r+1;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;	
	v arr[n];
	for(int i=0;i<n;i++) cin>>arr[i].x>>arr[i].y;
	ll A = 0;
	ll b = 0;	
	for(int i=0;i<n;i++){
		A+= arr[i]^arr[(i+1)%n];		
		b+=cnt(arr[i],arr[(i+1)%n]);
	}
	b-=n;
	A = abs(A);
	ll i = A-b+2;	
	cout<<i/2<<" "<<b<<"\n";
	return 0;
}
