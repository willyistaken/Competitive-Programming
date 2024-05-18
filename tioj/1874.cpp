/*#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1e7+2;
short d[MAXN];
short num[MAXN];
int x[MAXN];
vector<int> prime;
void init(){
	d[1]=1;
	num[1]=1;
	x[1]=1;
	for(int i=2;i<MAXN;i++){
		if(!x[i]){
			d[i]=2;
			x[i]=i;
			num[i]=1;
			prime.push_back(i);
		}
		for(int k=0;k<prime.size() && i*prime[k]<MAXN && prime[k]<=x[i];k++){
			if(x[i]==prime[k]){
				x[prime[k]*i] = prime[k];
				num[prime[k]*i] = num[i]+1;
				d[prime[k]*i] = (d[i]/(num[i]+1)) * (num[i]+2);
			}else{
				d[prime[k]*i] = d[i]*2;
				x[prime[k]*i] = prime[k];
				num[prime[k]*i]=1;
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	init();
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		cout<<d[n]<<"\n";
	}
	return 0;
}
*/

// 2nd attempt: don't needs to do this by brute force n + n/2 + n/3 + n/4 ... = o(nlogn);

/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e7 +5;
int d[MAXN];

void init(){
	for(int i=1;i<MAXN;i++){
		for(int j=1;j*i<MAXN;j++){
			d[i*j]+=1;
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	init();
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		cout<<d[n]<<"\n";
	}

	return 0;
}
*/ 
//doesn't work 1e7 will TLE in nlog(n);

//3th: memory optimize version of 1
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e7+2;
short d[MAXN];
char num[MAXN];
vector<short> prime;

#include <unistd.h>
char OB[65536]; int OP;
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){static char c;int a;while((c=RC())<'0');a=c^'0';while((c=RC())>='0')a*=10,a+=c^'0';return a;}

void init(){

	d[1]=1;
	num[1]=1;
	for(int i=2;i<MAXN;i++){
		if(!num[i]){
			d[i]=2;
			num[i]=1;
			if(i<65536 )prime.push_back(i);//sqrt(1e7)<65536
		}
		for(int k=0;k<prime.size() && i*prime[k]<MAXN;k++){
			if(i%prime[k]==0){
				num[prime[k]*i] = num[i]+1;
				d[prime[k]*i] = (d[i]/(num[i]+1)) * (num[i]+2);
				break;
				//using this condition to make sure that the smallest prime is prime[k]
			}else{
				d[prime[k]*i] = d[i]*2;
				num[prime[k]*i]=1;
			}
		}
	}
}


int main(){
	init();
	int t;t=R();
	while(t--){
		int n = R();
		printf("%d\n",d[n]);
	}
	return 0;
}
