#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,s,t;
struct matrix{
	int _s;
	vector<vector<int> > arr;

	void inp(){
		for(int i=0;i<m;i++){
			int a,b;cin>>a>>b;
			a--;b--;
			arr[a][b]+=1;
			arr[b][a]+=1;
		}
	}
	void init(int v){
		for(int i=0;i<n;i++){
			arr.push_back(vector<int>(n));
			for(int j=0;j<n;j++){
				if(i==j) arr[i][j]=v;
				else arr[i][j]=0;
			}
		}
	}
	void print(){
		for(auto i : arr){
			for(auto j:i){
				cout<<j<<" ";
			}
			cout<<"\n";
		}
	}
};
const int MOD = 1e9+9;
matrix operator*(const matrix &a,const matrix &b){
	matrix r;
	r.init(0);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				r.arr[i][j]+=(1LL*a.arr[i][k]*b.arr[k][j])%MOD;
				r.arr[i][j]%=MOD;
			}
		}
	}
	return r;
}

matrix power(matrix &a,ll nu){
	matrix r;
	r.init(1);
	while(nu){
		if(nu & 1) r=r*a;
		a=a*a;
		nu>>=1;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s>>t;
	s--;t--;
	ll k;cin>>k;
	matrix side;
	side.init(0);
	side.inp();
	side = power(side,k);
	cout<<side.arr[t][s]<<"\n";
	

	return 0;
}
