#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbd
const ll INF = 1e18+1e17;
struct Matrix{
	vector<vector<ll> > arr;
	int n;
	void init(int s){
		n = s;
		arr.resize(n);
		for(int i=0;i<n;i++){
			arr[i].resize(n);
		}
	}
	void fill(ll v){
		for(int i=0;i<n;i++){
			std::fill(arr[i].begin(),arr[i].end(),INF);
		}
		for(int i=0;i<n;i++) arr[i][i]=v;
	}
	void print(){
		for(int i=0;i<n;i++){
			cout<<"|";
			for(int j=0;j<n;j++) cout<<arr[i][j]<<",|"[j==n-1];
			cout<<"\n";
		}
	}
};

Matrix mul(Matrix a,Matrix b){
	Matrix r;
	r.init(a.n);
	r.fill(INF);
	for(int i=0;i<r.n;i++){
		for(int j=0;j<r.n;j++){
			for(int k=0;k<r.n;k++){
				r.arr[i][j] = min(r.arr[i][j],(a.arr[i][k]+b.arr[k][j]));
			}
		}
	}
	return r;
}

Matrix pow(Matrix a,ll p){
	Matrix r;
	r.init(a.n);
	r.fill(0);
	while(p){
		if(p&1) r = mul(r,a);
		a = mul(a,a);
		p>>=1;
	}
	return r;
}





int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	Matrix graph;
	graph.init(n);
	graph.fill(INF);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		int c;cin>>c;
		a--;b--;
		graph.arr[a][b] = min(graph.arr[a][b],1LL*c);
	}
	graph = pow(graph,k);
	if(graph.arr[0][n-1]>=1e18+1e17){
		cout<<-1<<"\n";
	}else{
		cout<<graph.arr[0][n-1]<<"\n";
	}
	return 0;
}

