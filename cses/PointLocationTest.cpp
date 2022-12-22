#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct v{
	int x;
	int y;
};

ll operator^(const v &a,const v &b){
	return 1LL*a.x*b.y-1LL*a.y*b.x;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int X1,Y1,X2,Y2,X3,Y3;
		cin>>X1>>Y1>>X2>>Y2>>X3>>Y3;
		v v1 = {X2-X1,Y2-Y1};
		v v2 = {X3-X1,Y3-Y1};
		ll k = v2^v1;
		if(k>0) cout<<"RIGHT\n";
		else if(k==0) cout<<"TOUCH\n";
		else cout<<"LEFT\n";
	}

	return 0;
}
