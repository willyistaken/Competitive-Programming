#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,MOD;
int tpower[10];
struct matrix{
	int arr[3][3];
	void init(int v){
		memset(arr,0,sizeof(arr));
		if(v<=0){
			for(int i=0;i<3;i++) arr[i][i] = abs(v);
		}else{
			arr[0][0]=1;
			arr[1][0]=1;arr[1][1]=1;
			arr[2][0]=1;arr[2][1]=1;arr[2][2] = tpower[v];
		}
	}
	void print(){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				cerr<<arr[i][j]<<" ";
			}
			cerr<<"\n";
		}
	}
};

matrix operator*(const matrix &a,const matrix &b){
	matrix r;
	r.init(0);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				r.arr[i][j]+=(a.arr[i][k]*b.arr[k][j])%MOD;
				r.arr[i][j]%=MOD;
			}
		}
	}
	return r;
};

matrix power(matrix a,int p){
	matrix r;
	r.init(-1);
	while(p){
		if(p&1) r = r*a;
		a = a*a;
		p>>=1;
	}
	return r;
}


int main(){
	while(cin>>n>>MOD){
	tpower[0]=1%MOD;
	for(int i=1;i<10;i++){
		tpower[i] = (10*tpower[i-1])%MOD;
	}
	int nlen=0;
	int ten=1;
	for(int i=1;i<10;i++){
		ten*=10;
		if(n<ten){
			nlen=i;
			break;
		}
	}
	matrix f;
	f.init(1);
	if(n<10){
		f = power(f,n-1);
		cout<<(f.arr[2][0]+f.arr[2][1]+f.arr[2][2])%MOD<<"\n";
	}else{
		f = power(f,8);
		int po = 90;
		for(int i=2;i<nlen;i++){
			matrix nextgroup;
			nextgroup.init(i);
			nextgroup = power(nextgroup,po);
			po*=10;
			f = nextgroup*f;
		}
		int ten=1;
		for(int i=1;i<nlen;i++) ten*=10;
		ten--;
		n-=ten;
		matrix lastgroup;
		lastgroup.init(nlen);
		lastgroup = power(lastgroup,n);


		f= lastgroup*f;
		cout<<(f.arr[2][0]+f.arr[2][1]+f.arr[2][2])%MOD<<"\n";
	}
	}
	return 0;
}
