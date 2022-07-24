#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6+5;
const int MOD = 1e9+7;

int fac[MAXN];

void init(){
	fac[1]=1;	
	for(int i=2;i<MAXN;i++){
		fac[i] = (1LL*fac[i-1]*i)%MOD;
	}
	
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
		

	return 0;
}

// the same the way to 1. partition n stuff in to n/k loop, 2. find the differnce permutation of a size n/k loop
/*
AHA. by simple mutiplie principle, a loop of size g have (g-1)! permutations;
STUCK: now what?




*/
