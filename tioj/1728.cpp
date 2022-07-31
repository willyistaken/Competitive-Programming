#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e7+2;
short d[MAXN];
void init(){
	d[0]=500;
	for(int i=1;i<MAXN;i++){
		for(int j=1; (j*i) < MAXN ; j++){
			d[j*i]+=1;
		}
	}
}
int mx(int a,int b){
	if(d[a]!=d[b]){
		if(d[a]>d[b]) return a;
		else return b;
	}
	if(a>b) return a;
	else return b;
}
int st[MAXN][24];
int main(){
	init();
	for(int p=0;p<24;p++){
		for(int i=0;i+(1<<p)<MAXN;i++){
		 	if(!p) st[i][p]=i;
			else{
				st[i][p] = mx(st[i][p-1],st[i+(1<<(p-1))][p-1]);
			}
		}
	}
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF){
		if(a>b) swap(a,b);
		b++;
		int p = 31-__builtin_clz(b-a);
		int ans = mx(st[a][p],st[b-(1<<p)][p]);
		printf("%d\n",ans);
	}

	return 0;
}

// big const rmq and divisor function (note : linear sieve uses alot of memories)
