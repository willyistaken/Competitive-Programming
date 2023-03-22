#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<cstdio>

//#include<bits/extc++.h>
//__gnu_pbds

int min(int& a,int& b){
	return  (a<b)?(a):(b);
}

int main(){
	int allz = 0;
	int allo = 0;
	char c;
	while((c=getchar_unlocked())>='0') (c&1)?(allz = ((allo<allz)?(allo):(allz))+1):(allo = ((allo<allz)?(allo):(allz))+1);
	printf("%d\n",allo);
	return 0;
}
