#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct matrix{
	unsigned arr[2][2];
	void init(unsigned v){
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				if(i==j) arr[i][j]=v;
				else arr[i][j] = 0;
			}
		}
	}

	void print(){
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
};

matrix operator*(const matrix &a,const matrix &b){
	matrix r;
	r.init(0);
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				r.arr[i][j]+=a.arr[i][k]*b.arr[k][j];
			}
		}
	}
	return r;
}


matrix power(matrix a,int n){
	matrix r;
	r.init(1);
	while(n){
		if(n&1) r = r*a;
		a = a*a;
		n>>=1;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	unsigned a,b,x,y;
	while(cin>>n && n>=0){
		cin>>a>>b>>x>>y;
		matrix mymatrix;
		mymatrix.arr[0][0]=0;
		mymatrix.arr[0][1]=1;
		mymatrix.arr[1][0]=x;
		mymatrix.arr[1][1]=y;
		mymatrix = power(mymatrix,n);
		cout<<mymatrix.arr[0][0]*a+mymatrix.arr[0][1]*b<<"\n";
	}

	return 0;
}
