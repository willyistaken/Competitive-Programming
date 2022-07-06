#pragma GCC optimize("Ofast")
#include <stdio.h>
using namespace std;
#define ll long long;
char L1[50005];
char L2[50005];
int L1size;
int L2size;
void readstring(){
	int d=0;
	while(true){
		if(!(L1[d]=getchar())) break;
		if(L1[d]=='\n') break;
		d++;
	}
	L1size=d;
	d=0;
	while(true){
		if(!(L2[d]=getchar())) break;
		if(L2[d]=='\n') break;
		d++;
	}
	L2size=d;
}
int main(){
	readstring();
	int maxn=0;
	for(int i=0;i<L1size;i++){
		int n=0;
		for(int j=0;i+j<L2size;j++){
			if(L1[j]==L2[i+j]) ++n;
		}
		maxn = (maxn>n) ? maxn:n;
	}
	for(int i=0;i<L2size;i++){
		int n=0;
		for(int j=0;i+j<L1size;j++){
			if(L1[i+j]==L2[j]) n++;
		}
		maxn = (maxn>n) ? maxn:n;
	}
	printf("%d",maxn);
}

//據說這題常數夠小可這樣做，但正解是FFT
//FFT解:




//to be continue;
