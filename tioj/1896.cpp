#pragma GCC optimize("Ofast")
#include "lib1896.h"
#include<vector>
#include <algorithm>
using namespace std;

vector<int> num;
void initialize(int n){
	 num.resize(n);
	 fill(num.begin(),num.end(),0);
	 return ;
}

int hasEdge(int a,int b){
	if(a<b) a=b;
	return (++num[a]==a);
}

