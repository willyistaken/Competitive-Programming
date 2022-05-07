#pragma GCC optimize("Ofast")
#pragma loop_opt(on)
#include<algorithm>
#include <iostream>
#define FOR(i,n) for(int i=0;i<n;++i)
using namespace std;
typedef unsigned uint;
const int S = 1<<18;

constexpr int MAXN = 1e5;
constexpr int MAXL = 18;

uint maxval[MAXL][MAXN], minval[MAXL][MAXN];

int n, m, l, r, hb;

int main(){
	cin>>n>>m;	
	FOR(i,n) cin>>maxval[0][i], minval[0][i]=maxval[0][i];
	for(uint j = 1; j < MAXL; j++)
		for(uint i = 0; i + (1 << j) - 1 < n; i++){
			minval[j][i] = std::min(minval[j-1][i], minval[j-1][i + (1 << (j-1))]),
			maxval[j][i] = std::max(maxval[j-1][i], maxval[j-1][i + (1 << (j-1))]);
		}
	for(; m; --m){
		cin>>l>>r;l--;r--; hb = 31 - __builtin_clz(r - l + 1);
		
		cout<<std::max(maxval[hb][l], maxval[hb][r - (1 << hb) + 1]) - std::min(minval[hb][l], minval[hb][r - (1 << hb) + 1])<<endl;
		
	}
	return 0;
}
