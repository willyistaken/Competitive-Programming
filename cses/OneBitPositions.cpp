#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
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
	cp cur(1,0);cp step(cos(2*PI/n),sin(rev*2*PI/n));
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
	string s;cin>>s;
	int n = s.size();
	int N = 1;
	while(N<=2*n) N*=2; 
	vector<cp> a(N);
	vector<cp> b(N);
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			a[i]+=1;
			b[n-i+1]+=1;
		}
	}
	fft(a,1);
	fft(b,1);
	for(int i=0;i<N;i++) a[i]*=b[i];
	fft(a,-1);
	for(int i=n+2;i<=2*n;i++){
		cout<<llround(a[i].real())<<" ";
	}
	cout<<"\n";
	return 0;
}
