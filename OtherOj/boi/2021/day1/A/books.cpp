#include <bits/stdc++.h>

#include "books.h"

using namespace std;
typedef long long ll;
//
// --- Sample implementation for the task books ---
//
// To compile this program with the sample grader, place:
//     books.h books_sample.cpp sample_grader.cpp
// in a single folder and run:
//     g++ books_sample.cpp sample_grader.cpp
// in this folder.
//
map<int,ll> mem;
int n;
ll get(int k){
	if(k>n) return 4e17;
	if(mem.count(k)) return mem[k];
	mem[k] = skim(k);
	return mem[k];
}
void solve(int N, int K, long long A, int S) {
	int l = 0;int r=N+1;
	n = N;
	while(r-l>1){
		int m = (l+r)/2;
		if(get(m)>=A) r = m;
		else l = m;
	}
	if(r<=K){
		ll sum=0;
		for(int i=1;i<=K;i++){
			sum+=get(i);
		}
		if(sum>2*A){
			impossible();
			return;
		}else{
			vector<int> ans;	
			for(int i=1;i<=K;i++) ans.push_back(i);
			answer(ans);
			return ;
		}
	}
	ll sum = 0;
	for(int i=1;i<K;i++){
		sum+=get(i);
	}
	sum+=get(r);
	if(sum<=2*A){
		vector<int> ans;
		for(int i=1;i<K;i++) ans.push_back(i);
		ans.push_back(r);
		answer(ans);
		return ;
	}
	sum-=get(r);
	sum+=get(K);
	vector<int> stk;
	for(int i=1;i<=K;i++) stk.push_back(i);
	vector<int> other;
	for(int i=r-1;i>=r-K;i--){
		if(sum>=A && sum<=2*A)	{
			vector<int> ans;
			for(auto v : stk) ans.push_back(v);
			for(auto v : other) ans.push_back(v);
			answer(ans);
			return;
		}
		int c = stk.back();
		stk.pop_back();
		sum-=get(c);
		other.push_back(i);
		sum+=get(i);
	}
		if(sum>=A && sum<=2*A)	{
			vector<int> ans;
			for(auto v : stk) ans.push_back(v);
			for(auto v : other) ans.push_back(v);
			answer(ans);
			return;
		}
		impossible();
		return ;

}
