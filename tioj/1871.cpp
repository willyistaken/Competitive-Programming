#include "lib1871.h"
#include <bits/stdc++.h>

int main() {
  int n = futa::init();
  int *A = futa::momo_gives_you_list_of_futa();
  int ans[n][22];
  memset(ans,0,sizeof(ans));
  for(int p=0;p<22;p++){
  	for(int i=0;i+(1<<p)<=n;i++){
		if(!p) ans[i][0]=A[i];
		else{
			ans[i][p] = min(ans[i][p-1],ans[i+(1<<(p-1))][p-1]);
		}
	}
  }
   int q = futa::momo_tells_you_q();
  while (q--) {
    std::pair<int,int> a = futa::momo_asks();
	a.second+=1;
	int p = 31-__builtin_clz(a.second-a.first);
	int g = min(ans[a.first][p],ans[a.second-(1<<p)][p]);
	futa::you_tell_momo(g);
  }
}
