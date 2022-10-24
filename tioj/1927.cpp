#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int MOD = 1e9+7;

int pow(int a,int p){
	int r = 1;
	while(p){
		if(p&1) r = (1LL*r*a)%MOD;
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}
vector<int> hsh;
vector<int> gp;
const int g = 17;
int get(int l,int r){
	l--;
	int m = gp[r-l];
	int newhs = (hsh[r] - (1LL*hsh[l]*m)%MOD)%MOD;
	if(newhs<0) newhs+=MOD;
	return newhs;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	hsh.resize(n+1,0);
	gp.resize(n+1,1);
	for(int i=1;i<=n;i++){
		int c;cin>>c;
		c = pow(c,(MOD-1)/2);
		hsh[i] = (hsh[i-1]*17LL)%MOD;
		if(c==1){
			hsh[i]+=1;
		}else{
			hsh[i]+=2;
		}
		gp[i] = (1LL*gp[i-1]*g)%MOD;
		//cout<<hsh[i]<<"\n";
	}
	while(q--){
		int i,j;cin>>i>>j;
		i++;j++;
		if(i>j) swap(i,j);
		//cout<<get(i,j)<<"\n";
		int l = 0;int r= n-j+2;
		while(r-l>1){
			int mid = (l+r)/2;
			if(get(i,i+mid-1)==get(j,j+mid-1)) l = mid;
			else r = mid;
		}
		cout<<l<<"\n";
	}
}
