#include<cstdio>
using namespace std;
typedef long long ll;

ll p[29][29];

void init(){
	for(int i=1;i<=28;i++){
		for(int j=1;j<=i;j++){
			if(j==1) p[i][j]=i;	
			else if(i==j) p[i][j]=i;
			else{
				p[i][j] = (p[i-1][j-1]*p[i][j-1])/(p[i][j-1]-p[i-1][j-1]);
			}
		}
	}
}

int main(){
	init();
	short r,c;scanf("%hu %hu",&r,&c);
	printf("%lld\n",p[r][c]);
	return 0;
}
