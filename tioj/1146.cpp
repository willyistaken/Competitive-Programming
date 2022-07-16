#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct matrix{
	vector<vector<int> >  arr;
	void init(int _m){
		arr.resize(_m);	
		for(int i=0;i<_m;i++){
			string s;cin>>s;
			for(int j=0;j<_m;j++){
				arr[i].push_back(s[j]-'0');
			}
		}
	}
	void start(int _m,int v){
		arr.resize(_m);
		for(int i=0;i<_m;i++){
			for(int j=0;j<_m;j++){
				if(i==j) arr[i].push_back(v);
				else arr[i].push_back(0);
			}
		}
	}

};

matrix operator*(const matrix &a,const matrix &b){
	matrix r;
	r.start((int)(a.arr).size(),0);
	int g = (a.arr).size();
	for(int i=0;i<g;i++){
		for(int j=0;j<g;j++){
			for(int k=0;k<g;k++){
				r.arr[i][j]+=a.arr[i][k]*b.arr[k][j];
			}
		}
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int m;cin>>m;
	matrix adj;
	adj.init(m);
	matrix r;
	r.start(m,1);
	int s,t,n;cin>>s>>t>>n;
	s--;t--;
	int ans=0;
	for(int i=0;i<n;i++){
		
		r = r*adj;
		ans+=r.arr[s][t];
	}
	cout<<ans<<"\n";
	return 0;
}
