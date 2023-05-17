#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include "lib2295.h"
#include <string.h>
#include <stdio.h>
typedef long long ll;

//#include<bits/extc++.h>
//__gnu_pbds


unsigned int B;
inline void func(unsigned int x,unsigned int p,unsigned int d,unsigned int a,unsigned int b,unsigned int M[8]){
	B = (p)?(b):(M[b]);
	M[d] = (x--)?((x--)?((x--)?((x--)?((x--)?((x--)?((x--)?((x--)?((x--)?((x--)?(~B):(M[a]<<((B<<27)>>27))):(M[a]>>((B<<27)>>27))):(M[a]^B)):(M[a]|B)):(M[a]&B)):((B)?((M[a]>=B)?(M[a]%B):(M[a])):(0))):((B)?((B>M[a])?(0):(M[a]/B)):(0))):(M[a]*B)):(M[a]-B)):(M[a]+B);
}
unsigned int myop[81][5];
int n;
void init_macro(int N,const unsigned int op[][5]){
		n = N;
		memcpy(myop,op,5*N*sizeof(unsigned int));
}

void run_macro(int t,unsigned int memory[8]){
	while(t--){
		for(int i=0;i<n;i++){
			func(myop[i][0],myop[i][1],myop[i][2],myop[i][3],myop[i][4],memory);
		}
	}
}

