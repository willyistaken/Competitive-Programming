#pragma GCC optimize("O2")
//#include "lib1227.h"
#include <iostream>
using namespace std;
typedef long long ll;

int N;
long long D[1000005];
bool question;
void init(int n, long long d[]) {
	N = n;
	D[0] = d[0];
	D[1] = d[1];
	for(int i=2;i<n;i++){
		D[i] = d[i]-d[i-2];
	}
}

void change(int a, int b, long long k) {
	D[a]+=-k;
	D[a+1]+=k;
	if((b+1)%2 == a%2) k = -k;
	D[b+2]+=k;
	D[b+1]+=-k;
	
/* 	DO[a]+=-k;
	DE[a]+=k;
	if(b<N-1){
		DO[b+1]+=k;
		DE[b+1]+=-k;
	} */
}
long long query(int c) {
	if(!question){
		for(int i=2;i<N;i++){
			D[i]=D[i-2]+D[i];
		}
	}
	question = 1;
	return D[c];
}

int main(){
	int n,m,q;cin>>n>>m>>q;
	long long d[n];
	for(int i=0;i<n;i++) cin>>d[i];
	init(n,d);
	for(int i=0;i<m;i++){
		int a,b;
		ll k;
		cin>>a>>b>>k;
		change(a,b,k);
	}
	for(int i=0;i<n;i++){
		cout<<query(i)<<" ";
	}
	cout<<endl;
}
