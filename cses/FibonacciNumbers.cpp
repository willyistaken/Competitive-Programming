#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int MOD = 1e9+7;
struct Matrix{
	vector<vector<int> > arr;
	int n;
	void init(int s){
		n = s;
		arr.resize(n);
		for(int i=0;i<n;i++){
			arr[i].resize(n);
		}
	}
	void fill(int v){
		for(int i=0;i<n;i++){
			std::fill(arr[i].begin(),arr[i].end(),0);
		}
		for(int i=0;i<n;i++) arr[i][i]=v;
	}
};

Matrix mul(Matrix a,Matrix b){
	Matrix r;
	r.init(a.n);
	r.fill(0);
	for(int i=0;i<r.n;i++){
		for(int j=0;j<r.n;j++){
			for(int k=0;k<r.n;k++){
				r.arr[i][j] +=((1LL*a.arr[i][k]*b.arr[k][j])%MOD);
				r.arr[i][j]%=MOD;
			}
		}
	}
	return r;
}

Matrix pow(Matrix a,ll p){
	Matrix r;
	r.init(a.n);
	r.fill(1);
	while(p){
		if(p&1) r = mul(a,r);
		a = mul(a,a);
		p>>=1;
	}
	return r;
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n;cin>>n;
	Matrix fib;
	fib.init(2);
	fib.arr[0][0]=0;fib.arr[0][1]=1;fib.arr[1][1]=1;fib.arr[1][0]=1;
	fib = pow(fib,n);
	cout<<fib.arr[0][1]<<"\n";	
	return 0;
}
