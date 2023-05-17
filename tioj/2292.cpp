#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<cstdio>

//#include<bits/extc++.h>
//__gnu_pbds
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
int min(int& a,int& b){
	return  (a<b)?(a):(b);
}

int main(){
	int allz = 0;
	int allo = 0;
	char c;
	while((c=getchar())>='0') (c&1)?(allz = ((allo<allz)?(allo):(allz))+1):(allo = ((allo<allz)?(allo):(allz))+1);
	printf("%d\n",allo);
	return 0;
}

