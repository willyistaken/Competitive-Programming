#include "Ali.h"
#include <string>
#include <vector>
#include<iostream>
#define pb push_back
using namespace std;
 
namespace {
	vector<int> dep, tab, gdzie;
	vector<vector<int> > E;
	int blo_siz=30;
	int blo_num=(1<<10);
	int max_pot=14;
string enc(int a){
	string res(max_pot, '0');
	for(int i=0; i<max_pot; i++){
		res[i]='0'+!!(a&(1<<i));
	}
	return res;
}
int dec(string s){
	int res=0;
	for(int i=0; i<s.size(); i++){
		res+=(1<<i)*(s[i]-'0');
	}
	return res;
}
}
void dfs(int v, int p){
	//cerr<<v<<" "<<p<<endl;
	gdzie[v]=tab.size();
	tab.pb(dep[v]);
	for(int u:E[v]){
		if(u!=p){
			dep[u]=dep[v]+1;
			dfs(u, v);
			tab.pb(dep[v]);
		}
	}
}
void Init(int n, std::vector<int> U, std::vector<int> V) {
	E.clear();
	gdzie.clear();
	dep.clear();
	tab.clear();
	gdzie.resize(n);
	dep.resize(n);
	E.resize(n);
	for(int i=0; i<n-1; i++){
		//cerr<<U[i]<<" "<<V[i]<<endl;
		E[U[i]].pb(V[i]);
		E[V[i]].pb(U[i]);
	}
	dfs(0, -1);
	for(int i=0; i<n; i++){
		SetID(i, gdzie[i]);
	}
	while(tab.size()%blo_siz){
		tab.pb(tab.back()+1);
	}
}
 
string SendA(std::string s) {
	int b1=dec(s.substr(0, 10)), b2=dec(s.substr(10, 10));
	int mini=(1<<max_pot)-1;
	string res;
	for(int i=b1+1; i<b2; i++){
		for(int j=i*blo_siz; j<(i+1)*blo_siz; j++){
			mini=min(mini, tab[j]);
		}
	}
	res+=enc(mini);
	res+=enc(tab[b1*blo_siz]);
	for(int i=b1*blo_siz+1; i<blo_siz*(b1+1); i++){
		res+='0'+char(tab[i]>tab[i-1]);
	}
	res+=enc(tab[b2*blo_siz]);
	for(int i=b2*blo_siz+1; i<blo_siz*(b2+1); i++){
		res+='0'+char(tab[i]>tab[i-1]);
	}
	return res;
}
