#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


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
				r.arr[i][j] +=a.arr[i][k]*b.arr[k][j];
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
