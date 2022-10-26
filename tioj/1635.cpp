#include<bits/stdc++.h>
#include "lib1635.h"
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n;

int modimax(int xi,int xj){
	if(xi==0) return xj;
	if(xj>n) return xi;
	return Max(xi,xj);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	n = Initialize();
	int l = 0;
	int r = n+1;
	while(r-l>1){
		int mid = (l+r)/2;
		if(modimax(mid-1,mid)==mid-1) r = mid;
		else l = mid;
	}
	Report(l);

	return 0;
}
