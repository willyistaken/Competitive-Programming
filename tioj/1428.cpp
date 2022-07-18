#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q,l;
const int MOD = 1e9+9;
struct matrix{
	vector<vector<int> > arr;
	void init(int v){
		arr.resize(n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				arr[i].push_back(((j==i)?v:0));
			}
		}
	}
	void print(){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++) cout<<arr[i][j]<<" ";
			cout<<"\n";
		}
	}
};

matrix operator*(const matrix &a,const matrix &b){
	matrix r;
	r.init(0);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				r.arr[i][j]+=(1LL*a.arr[i][k]*b.arr[k][j])%MOD;	
				r.arr[i][j] = (r.arr[i][j]>MOD) ? r.arr[i][j]-MOD:r.arr[i][j];
			}
		}
	}
	return r;
}

matrix power(matrix a,int p){
	matrix r;r.init(1);
	while(p){
		if(p&1) r = r*a;
		a = a*a;
		p>>=1;
	}
	return r;
}




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>q>>l;	
	matrix adj;
	adj.init(0);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		adj.arr[a][b]+=1;
	}
	adj = power(adj,l);
	while(q--){
		int a,b;cin>>a>>b;
		cout<<adj.arr[a][b]<<"\n";
	}
	return 0;
}
