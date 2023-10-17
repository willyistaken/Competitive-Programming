#include "Ali.h"
#include<iostream>
#include <string>
#include <vector>
#include<cassert>
#include<queue>
namespace {
std::vector<std::vector<int> > side;
int rN = 0;
std::vector<int> p[20];
std::vector<int> dep;
void dfs(int cur){
	for(int i : side[cur])	{
		if(!dep[i]){
			p[0][i]= cur;
			dep[i]=dep[cur]+1;
			dfs(i);
		}
	}
}
int dis(int a,int b){
	if(a==b) return 0;
	if(dep[a]>dep[b]) std::swap(a,b);
	int oga = a;
	int ogb = b;
	for(int i=19;i>=0;i--){
		if(dep[p[i][b]]>=dep[a]) b=p[i][b];
	}
	if(a==b) return dep[ogb]-dep[oga];
	for(int i=19;i>=0;i--){
		if(p[i][a]!=p[i][b]){
			a = p[i][a];
			b = p[i][b];
		}
	}
	b = p[0][b];
	a = p[0][a];
	int c = b;
	return dep[oga]+dep[ogb]-2*dep[c];
}
std::string dtb(int x){
	std::string s;
	for(int i=0;i<14;i++){
		if((x>>i)&1) s+='1';
		else s+='0';
	}
	return s;
}

}

void Init(int N, std::vector<int> U, std::vector<int> V) {
	rN=N;
	side.resize(N);
	dep.resize(N);
	for(int i=0;i<20;i++) p[i].resize(N);
	for(int i=0;i<N;i++){
		dep[i]=0;
		side[i].clear();
		for(int k=0;k<20;k++) p[k][i]=0;
	}
	for(int i=0;i<N-1;i++){
		side[U[i]].push_back(V[i]);
		side[V[i]].push_back(U[i]);
	}
	dep[0]=1;
	dfs(0);
	for(int j=1;j<20;j++)	{
		for(int i=0;i<N;i++) p[j][i] = p[j-1][p[j-1][i]];
	}
	for(int i=0;i<N;i++) SetID(i,i);
}

std::string SendA(std::string S) {
	std::string re;
	int a = 0;
	int b = 0;
	for(int i=0;i<6;i++){
		if(S[i]=='1'){
			if(S[14+i]=='1') a+=(1<<i);
			else b+=(1<<i);
		}else{
			if(S[14+i]=='1') {a+=(1<<i);b+=(1<<i);}
		}
	}

	for(int k=0;k<157;k++){
		int aa = a;
		int bb = b;
		for(int i=6;i<14;i++){
			if(S[i]=='1'){
				if((k>>(i-6))&1) aa+=(1<<i);
				else bb+=(1<<i);
			}else{
				if((k>>(i-6))&1) {aa+=(1<<i);bb+=(1<<i);}
			}
		}
		if(aa>=rN || bb>=rN) re+=dtb(0);
		else {re+=dtb(dis(aa,bb)); 
		}
	}
	return re;
}
