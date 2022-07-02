#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int f(int n,int k){
	if(n==1) return 0;
	else return (f(n-1,k)+k)%n;
}

int main(){
	int m;scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int n,k;
		scanf("%d %d",&n,&k);
		printf("Case %d: %d\n",i,(f(n,k)+1));
	}

	return 0;
}
