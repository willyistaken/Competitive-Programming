#include<bits/stdc++.h>
#include "interactive.h"
using namespace std;


int base;

vector<int> getarr(vector<int> pos){
	vector<int> s;
	if(pos.empty()) return s;
	vector<int> s1 = get_pairwise_xor(pos);
	pos.push_back(1);
	vector<int> s2 = get_pairwise_xor(pos);
	map<int,int> st;
	for(auto i : s2) st[i]++;
	for(auto i : s1) st[i]--;
	for(auto i : st){
		if(i.first!=0 && i.second) s.push_back(i.first^base);
	}
	return s;
}

map<int,int> mp;
vector<int> guess(int n){
	base  = ask(1);
	for(int i=0;i<7;i++){
		vector<int> pos;	
		for(int k=2;k<=n;k++){
			if(k&(1<<i)) pos.push_back(k);
		}
		vector<int> val = getarr(pos);
		for(auto g : val) mp[g]+=(1<<i);
	}
	vector<int> arr(n);
	for(auto i : mp){
		arr[i.second-1] = i.first;
	}
	arr[0] = base;
	return arr;
}

