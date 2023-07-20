#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


struct matrix{
	vector<vector<long double> > arr;
	void init(bool type){
		arr.resize(2);
		arr[0].resize(2);
		arr[1].resize(2);
		arr[0][0]=type;
		arr[0][1]=0;
		arr[1][0]=0;
		arr[1][1]=type;
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

matrix mul(matrix a,matrix b){
	matrix c;
	c.init(0);
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				c.arr[i][j]+=a.arr[i][k]*b.arr[k][j];
			}
		}
	}
	return c;
}

matrix pow(matrix a,ll p){
	matrix r;
	r.init(1);
	while(p){
		if(p&1) r = mul(r,a);
		a = mul(a,a);
		/*r.print();
		cout<<"r\n";
		a.print();
		cout<<"a\n";*/
		p>>=1;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n;cin>>n;
	if(n==1){
		cout<<"100 0\n";
		return 0;
	}
	if(n>=50){
		cout<<"33.3333333 66.66666666\n";
		return 0;
	}
	matrix ans;
	ans.init(2);
	ans.arr[0][0]=0;
	ans.arr[0][1]=1;
	ans.arr[1][0]=0.5;
	ans.arr[1][1]=0.5;
	n-=2;	
	//for(int i=1;i<=n;i++){
	matrix p = pow(ans,n);
	long double f = p.arr[1][0];
	cout<<fixed<<setprecision(8);
	cout<<100.0*f<<" "<<100.0*(1-f)<<"\n";
	//}
	return 0;
}
