#include "Ali.h"
#include<iostream>
#include <string>
#include <vector>
#include<cassert>
#include<queue>
#include<algorithm>
namespace {
std::vector<std::vector<int> > side;
int rN = 0;
std::vector<int> p[20];
std::vector<int> dep;
std::vector<int> dfn;
std::vector<int> dfn2ind;
int t = 0; 
std::vector<int> mt2t;
std::vector<int> dfmt;
int mt = 0;
void dfs(int cur){
	dfn[cur]=t++;
	dfmt[cur]=mt++;
	mt2t.push_back(dfn[cur]);
	dfn2ind.push_back(cur);
	for(int i : side[cur])	{
		if(!dep[i]){
			p[0][i]= cur;
			dep[i]=dep[cur]+1;
			dfs(i);
		}
	}
	t++;
	dfn2ind.push_back(p[0][cur]);
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
	dfn.resize(N);
	dfmt.resize(N);
	t=0;
	mt=0;
	dfn2ind.clear();
	mt2t.clear();
	for(int i=0;i<20;i++) p[i].resize(N);
	for(int i=0;i<N;i++){
		dfn[i]=0;
		dep[i]=0;
		dfmt[i]=0;
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
	/*
	for(int i=0;i<N;i++) std::cout<<dfmt[i]<<" ";
	std::cout<<'\n';
	for(int i=0;i<N;i++) std::cout<<dfn2ind[mt2t[dfmt[i]]]<<" ";
	std::cout<<'\n';
	*/
	for(int i=0;i<N;i++) SetID(i,dfmt[i]);
}

std::string SendA(std::string S) {
	//std::cout<<"ans:"<<dep[2015]<<" "<<dep[3582]<<"\n";
	std::string re;
	int xm = 0;
	int ym = 0;
	for(int i=0;i<10;i++){
		if(S[i]=='1') xm+=(1<<i);
		if(S[i+10]=='1')  ym+=(1<<i);
	}
	std::vector<int> pospos;
	for(int i=0;i<10;i++){
		if(xm+(1024)*i<rN) re+=dtb(dep[dfn2ind[mt2t[xm+(1024)*i]]]);		
		else re+=dtb(0);
		if(xm+(1024)*i<rN) pospos.push_back(mt2t[xm+(1024)*i]);
//		if(xm+(1024)*i<rN) std::cout<<xm+(1024)*i<<"->"<<dfn2ind[mt2t[xm+(1024)*i]]<<":"<<dep[dfn2ind[mt2t[xm+(1024)*i]]]<<" ";
	}
//	std::cout<<"\n";
	for(int i=0;i<10;i++){
		if(ym+(1024)*i<rN) re+=dtb(dep[dfn2ind[mt2t[ym+(1024)*i]]]);		
		else re+=dtb(0);
		if(ym+(1024)*i<rN) pospos.push_back(mt2t[ym+(1024)*i]);
//		if(ym+(1024)*i<rN) std::cout<<dfn2ind[mt2t[ym+(1024)*i]]<<":"<<dep[dfn2ind[mt2t[ym+(1024)*i]]]<<" ";
	}
//	std::cout<<"\n";
	std::sort(pospos.begin(),pospos.end());
	//for(auto i : dfn) std::cout<<i<<" ";
	//std::cout<<"\n";
	//for(auto i : dfn2ind) std::cout<<i<<" ";
	//std::cout<<std::endl<<"pospos:";
	//for(auto i : pospos) std::cout<<i<<" ";
	//std::cout<<"\n";
	for(int i=0;i<pospos.size()-1;i++){
		int minn = 1e9;
		for(int l=pospos[i];l<=pospos[i+1];l++)	{
			minn = std::min(minn,dep[dfn2ind[l]]);
		}
		re+=dtb(minn);
	}
	return re;	
}
