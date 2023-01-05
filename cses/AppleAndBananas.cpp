#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
typedef long double lb;
typedef complex<double> cp;
const double PI = 3.14159265358979;
void fft(vector<cp> &f,int rev){
	int n = f.size();
	if(n==1) return ;
	vector<cp> o,e;
	for(int i=0;i<n;i++){
		if(i&1) o.push_back(f[i]);
		else e.push_back(f[i]);
	}
	fft(o,rev);fft(e,rev);		
	cp cur(1,0);cp step(cos(2*PI/n),sin(2*PI*rev/n));
	for(int i=0;i<n/2;i++){
		f[i] = e[i]+cur*o[i];		
		f[i+n/2] = e[i]-cur*o[i];
		if(rev<0){
			f[i]/=2;
			f[i+n/2]/=2;
		}
		cur*=step;
	}
	
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int k,n,m;cin>>k>>n>>m;		
	int N = 1;
	while(N<=2*k) N<<=1;
	vector<cp> a(N);
	vector<cp> b(N);
	for(int i=0;i<n;i++){
		int w;cin>>w;
		a[w] +=1;
	}
	for(int j=0;j<m;j++){
		int w;cin>>w;
		b[w] +=1;
	}
	fft(a,1);
	fft(b,1);
	for(int i=0;i<N;i++) a[i]*=b[i];
	fft(a,-1);
	for(int i = 2;i<=2*k;i++) cout<<llround(a[i].real())<<" ";
	cout<<"\n";
	return 0;
}
