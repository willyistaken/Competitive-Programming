#include <vector>
#include <utility>
#include<bits/stdc++.h>
#pragma GCC target("popcnt")
#pragma GCC optimize("Ofast")
const int N = 256;
namespace {
int V;
const int B = 32;
}
using namespace std;
typedef long long ll;
struct matrix{
	bitset<N> M[N];	
	void print(){
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++) cout<<M[i][j];
			cout<<"\n";
		}
	}
};

map<ll,matrix> computed;

matrix I;
matrix G[B];

void mul(matrix &a,const matrix &b){
	matrix T;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++) T.M[i][j] = a.M[j][i];
	}
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			a.M[i][j] = (b.M[i]&T.M[j]).any();
		}
	}
}

void p2(matrix &a){
	matrix T;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++) T.M[i][j] = a.M[j][i];
	}
	matrix R;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			R.M[i][j] = (a.M[i]&T.M[j]).any();
		}
	}
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++) a.M[i][j] = R.M[i][j];
	}
}
void initialize(int n, std::vector<std::pair<int, int>> segments) {
	V = n;
	for(auto i : segments){
		I.M[i.first-1][i.second-1]=1;
	}
	G[0]=I;
	for(int i=1;i<B;i++){
		G[i]=G[i-1];
		p2(G[i]);
	}
	for(int i=0;i<B;i++){
		matrix TEMP=G[i];
		for(int k=0;k<V;k++){
			for(int j=0;j<V;j++) G[i].M[k][j]=TEMP.M[j][k];
		}
	}
	
}

matrix po(const matrix A,ll p){
	matrix R;
	matrix f = A;
	for(int i=0;i<V;i++) R.M[i][i]=1;
	while(p){
		if(p&1) mul(R,f);
		p2(f);
		p>>=1;
	}
	return R;
}

bool has_route(int s, int t, long long k) {
	s--;t--;
	bitset<N> v;
	v[s]=1;
	for(int i=0;i<B;i++){
		if((k>>i)&1){
			bitset<N> f=v;
			for(int j=0;j<V;j++){
				v[j] = (f&G[i].M[j]).any();
			}
		}
	}
	return (v[t]);
}
