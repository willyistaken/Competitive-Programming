#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include<bits/stdc++.h>
#include "lib1860.h"
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int main(){
	int T = Start_The_Loli_Dream();
	while(T--){
		int n = Count_How_Many_Loli();
		int s = (n==8)?(3):(37);
		int maxn = 0;
		bool choose = 0;
		for(int i=1;i<=n;i++){
			int k = Get_Loli_Moeness();
			if(i>s){
				if(k>=maxn){
					You_Choose_This_Loli();
					choose=1;
					break;
				}
			}
			maxn = max(maxn,k);
		}
		if(!choose)	You_Choose_This_Loli();
	}
}

