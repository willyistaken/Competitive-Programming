#include<cstdio>
using namespace std;
typedef long long ll;

int f[50];

int ans(int n,int k){
	if(n>=47) return ans(n-2,k);
	if(k>f[n]) return -1;
	if(n<=2) return n-1;
	if(k>f[n-2]) return ans(n-1,k-f[n-2]);
	return ans(n-2,k);
}

int main(){
	f[0]=0;
	f[1]=1;
	f[2]=1;
	for(int i=3;i<50;i++){
		f[i] = f[i-1]+f[i-2];
	}
	int t;scanf("%d",&t);
	while(t--){
		int n,k;scanf("%d%d",&n,&k);
		printf("%d\n",ans(n,k));
	}
	return 0;
}

// by observation:
/*
A(n,k) = 
	if k > fn = -1
	if n<=2 = n-1
	if k>fn-2 = A(n-1,k-f(n-2))
	if k<= fn-2 = A(n-2,k);
*/
