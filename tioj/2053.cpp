#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9+7;

struct matrix{
	int arr[2][2];
	void init(int v){
		arr[0][0]=v;
		arr[0][1]=0;
		arr[1][0]=0;
		arr[1][1]=v;
	}
	void print(){
		cout<<"\n";
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
	}
};

matrix operator*(const matrix &a,const matrix &b){
	matrix r;
	r.init(0);
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				r.arr[i][j]+=(1LL*a.arr[i][k]*b.arr[k][j])%MOD;
				r.arr[i][j]%=MOD;
			}
		}
	}
	return r;
}

matrix power(matrix a,int n){
	matrix r;
	r.init(1);
	while(n){
		if(n&1) r=r*a;
		a = a*a;
		n>>=1;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int x1,x2,a,b,n;cin>>x1>>x2>>a>>b>>n;
	matrix fib;
	fib.arr[0][0]=0;fib.arr[0][1]=1;fib.arr[1][0]=a;fib.arr[1][1]=b;
	fib = power(fib,n-1);
	int ans = (1LL*fib.arr[0][0]*x1)%MOD;
	ans+=(1LL*fib.arr[0][1]*x2)%MOD;
	cout<<ans%MOD<<"\n";
	return 0;
}
