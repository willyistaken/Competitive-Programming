#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
typedef complex<double> cp;
const double PI = acos(-1);

void fft(vector<cp> &f,int rev){
	int n = f.size();
	if(n==1) return ;
	vector<cp> o(n/2),e(n/2);	
	for(int i=0;i<n;i++){
		if(i&1) o[i/2]= f[i];
		else e[i/2] = f[i];
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
	string a,b;cin>>a>>b;
	int k = a.size()+b.size();	
	int N = 1;
	while(N<2*k) N*=2;
	vector<cp> x(N);
	vector<cp> y(N);
	for(int i=0;i<a.size();i++){
		x[a.size()-i-1]  = (a[i]-'0');
	}
	for(int j=0;j<b.size();j++){
		y[b.size()-j-1] = (b[j]-'0');
	}
	fft(x,1);
	fft(y,1);
	for(int i=0;i<N;i++) x[i]*=y[i];
	fft(x,-1);
	stack<char> ans;
	for(int i=0;i<N;i++){
		ll g = llround(x[i].real());
		ans.push('0'+(g%10));
		g/=10;
		if(i!=N-1) x[i+1]+=g;
	}
	bool output = 0;
	while(ans.size()){
		output|=(ans.top()!='0');
		if(output){
			cout<<ans.top();
		}
		ans.pop();
	}
	return 0;
}
