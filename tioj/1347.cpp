#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

#include <unistd.h>
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){static char c;int a;while((c=RC())<'0');a=c^'0';while((c=RC())>='0')a*=10,a+=c^'0';return a;}

double powerd(double a,int p){
	double r = (double) a;
	double result=1;
	while(p){
		if(p&1) result*=r;
		r=r*r;	
		p>>=1;
	}
	return result;
}

__int128 powerl(__int128 a,int p){
	__int128 r=1;
	while(p){
		if(p&1) r*=a;
		a=a*a;
		p>>=1;
	}
	return r;
}


int n,k,p;
vector<ll> sum;
vector<ll> L;
vector<double> tempdp;

struct segment{
	int l;
	int r;
	int id;
};

bool better(int a,int b,int r){
	return ( tempdp[a] + powerd( fabs( (double)(sum[r]-sum[a]-L[r]-k) ) , p))<=( tempdp[b] + powerd( fabs( (double)(sum[r]-sum[b]-L[r]-k) ) , p));	
}

int main(){
	n = R();k=R();p = R();
	sum.resize(n+1,0);
	L.resize(n+1,0);
	tempdp.resize(n+1);
	tempdp[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]=R();
	}
	for(int i=1;i<n;i++){
		L[i]=R();
		sum[i] = sum[i]+sum[i-1]+L[i];
	}
	int tranpoint[n+1]={0};
	sum[n]+=sum[n-1];
	deque<segment> range;
	range.push_back({1,n+1,0});
	for(int i=1;i<=n;i++){
		if(range.size()>1){
			if(better(range[1].id,range[0].id,i) || range[0].r<i) range.pop_front();	
			
		}
		int tr = range[0].id;
		tempdp[i] = tempdp[tr]+powerd(fabs((double)(sum[i]-sum[tr]-L[i]-k)),p);
		tranpoint[i] = tr;
		int s = range.size();
		while(  s){
			s = range.size();
			if(better(i,range[s-1].id,range[s-1].l)) range.pop_back();	
			else break;
		}
		if(range.size()){
			s = range.size();
			if(better(range[s-1].id,i,n)) continue;
			int l = range[s-1].l;int r = range[s-1].r;
			while(r-l>1){
				int mid = (l+r)/2;
				if(better(i,range[s-1].id,mid)) r = mid;
				else l = mid;
			}
			segment per = {range[s-1].l,r,range[s-1].id};
			range.pop_back();
			range.push_back(per);
			range.push_back({r,n+1,i});
		}
	}
	__int128 dp[n+1]={0};
	for(int i=1;i<=n;i++){
		int tr = tranpoint[i];
		dp[i] = dp[tr]+powerl(labs(sum[i]-sum[tr]-L[i]-k) , p);	
	}
	printf("%lld\n",(long long)dp[n]);
	return 0;
}
