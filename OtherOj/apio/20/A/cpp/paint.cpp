#include "paint.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int minimumInstructions(int N, int M, int K, std::vector<int> C,std::vector<int> A, std::vector<std::vector<int>> B) {
  vector<int> ok(N,0);
  vector<vector<int> > loc(K);
  for(int i=0;i<M;i++){
  	for(auto e : B[i]){
		loc[e].push_back(i);
	}
  }
  vector<vector<int>> longp(M,vector<int>(2,0));
  stack<int> prev;
  for(int i=0;i<N;i++){
  	  int maxn = 0;
	  for(auto j : loc[C[i]]){
	  	int f = (j-1)%M;
		if(f<0) f+=M;
	  	longp[j][i&1] = longp[f][(i&1)^1]+1;
		maxn = max(maxn,longp[j][i&1]);
	  }
	  while(prev.size()) {
	  	longp[prev.top()][(i&1)^1]=0;
		prev.pop();
	  }
	  for(auto j : loc[C[i]]) prev.push(j);
	  if(maxn>=M) ok[i-M+1]=1;
  }



  int ans = 0;
  vector<bool> colored(N,0);
  int maxn = -1e9;
  for(int i=0;i<N;i++){
  	if(ok[i]) maxn = max(maxn,i);
	if(!colored[i]){
		ans++;
		int k = maxn+M-1;
		if(k<i) return -1;
		for(int h=i;h<=k;h++) colored[h]=1;
	}
  }
  return ans;
}
