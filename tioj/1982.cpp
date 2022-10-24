#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

typedef complex<__int128> c;
__int128 absn(__int128 x){
	return (x>0)?(x):(-x);
}

__int128 norm(c a){
	return (a.real()*a.real())+(a.imag()*a.imag());
}

c con(c &a){
	return c(a.real(),-a.imag());
}

__int128 close(__int128 x,__int128 m){
	__int128 v= x%m;
	if(v<0){
		if(2*absn(v)>m) return (x/m)-1;
		else return x/m;
	}else{
		if(2*absn(v)>m) return (x/m)+1;
		else return x/m;
	}
}

c operator%(c a,c b){
		if(norm(a)<norm(b)) return a;
		c r = a*con(b);	
		r = c(close(r.real(),norm(b)),close(r.imag(),norm(b)));
		return a-(r*b);
}

c gcd(c a,c b){
	if(norm(b)==0) return a;
	return gcd(b,a%b);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	c g;
	ll a,b;cin>>a>>b;
	g = c((__int128)a,(__int128)b);
	for(int i=0;i<5;i++){
		ll a,b;cin>>a>>b;
		g = gcd(g,c((__int128)a,(__int128)b));
	}
	cout<<(ll)(absn(g.real())+absn(g.imag()))<<"\n";
	return 0;
}

// learn euclidean ring(can gcd)
