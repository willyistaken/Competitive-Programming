#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,s; ll t;
struct matrix{
	vector<vector<ll> > arr;
	void init(ll f,ll v){
		arr.resize(n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				arr[i].push_back(((i==j)?(v):(f)));
			}
		}
	}
	void print(){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cerr<<arr[i][j]<<" ";
			}
			cerr<<"\n";
		}
	}
};

matrix operator*(matrix &a,matrix &b){
	matrix r;
	r.init(LONG_LONG_MIN,LONG_LONG_MIN);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				r.arr[i][j] = max(r.arr[i][j],a.arr[i][k]+b.arr[k][j]);
			}
		}
	}
	return r;
}

matrix power(matrix a,ll p){
	matrix r;
	r.init(-1e18,-1e18);
	r.arr[s][s]=0;
	while(p){
		if(p&1) r = r*a;
		a = a*a;
		p>>=1;
	}
	return r;
}



int main(){
    cin>>n>>m;
	cin>>s>>t;
	s--;
	matrix ma;
	ma.init(-1e18,-1e18);
	int w[n];
	for(int i=0;i<n;i++) cin>>w[i];
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		a--;b--;
		ma.arr[a][b] = w[b];
	}
	ma = power(ma,t);
	ll maxn=LONG_LONG_MIN;
	for(int i=0;i<n;i++){
		maxn = max(maxn,ma.arr[s][i]);
	}
	cout<<maxn<<"\n";

}
