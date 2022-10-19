#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
const int MOD = 1e9+7;
int N;
ll K;

struct matrix{
	vector<vector<int> > arr;
	matrix():arr(vector<vector<int>>(N,vector<int>(N,0))){}
	void init(int v){
		for(int i=0;i<N;i++) arr[i][i]=v;
	}
	void print(){
		cerr<<"\n";
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++) cerr<<arr[i][j]<<" ";
			cerr<<"\n";
		}
	}
};

matrix operator*(matrix &a,matrix &b){
	matrix r;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				r.arr[i][j] += (1LL*a.arr[i][k]*b.arr[k][j])%MOD;
				r.arr[i][j]%=MOD;
			}
		}
	}
	return r;
}

matrix pow(matrix a,ll p){
	matrix r ;
	r.init(1);
	while(p){
		if(p&1) r = r*a;
		a = a*a;
		p>>=1;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>N>>K;
	int e[N+1];
	int p[N+1];
	p[0]=N;
	e[0]=1;
	for(int i=1;i<=N;i++){
		cin>>e[i];
		if(i&1) e[i]*=-1;
	}
	for(int k=1;k<=N;k++){
		p[k] = 0;
		for(int i = 1;i<k;i++){
			int stuff = (1LL*e[k-i]*p[i])%MOD;
			if((k-1+i)&1) stuff*=-1;
			p[k]+=stuff;
			p[k]%=MOD;
		}
		p[k]+=(((k&1)?(1LL):(-1LL))*k*e[k])%MOD;
		p[k]%=MOD;
		if(p[k]<0) p[k]+=MOD;
	}
	if(K<=N){
		cout<<p[K]<<"\n";
		return 0;
	}
	/*for(int i=0;i<=N;i++) cerr<<p[i]<<" ";
	cerr<<"\n";*/
	matrix v;
	for(int i=0;i<N-1;i++){
		v.arr[i][i+1]=1;
	}
	for(int i=0;i<N;i++){
		v.arr[N-1][i] = e[N-i];
		if((N-i+1)&1) v.arr[N-1][i]*=-1;
	}
	//v.print();
	matrix result = pow(v,K-N);
	int ans = 0;
	for(int i=0;i<N;i++){
		ans+=(1LL*result.arr[N-1][i]*p[i+1])%MOD;
		ans%=MOD;
	}
	//result.print();
	if(ans<0) ans+=MOD;
	cout<<ans<<"\n";
}


// newton's identities;

//pk = (-1)^(k-1)kek + sum(1~k-1)((-1)^(k-1+i)ek-ipi); for k<=n
// pk = sum(k-n~k-1)(-1)^(k-1+i)ek-ipi

