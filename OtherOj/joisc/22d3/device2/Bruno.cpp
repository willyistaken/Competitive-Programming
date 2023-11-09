#include "Bruno.h"
#include <utility>
#include <vector>
#include<iostream>
using namespace std;

long long Bruno(std::vector<int> u) {
	int a = 0;
	vector<int> ans;
	ans.push_back(0);
	long long A = 0;
	long long p = 1;
	for(auto i : u){
		if(i==0) a--;
		else a++;
		if(a==3){//mod 3 ==0
			A+=p;	
			p<<=1;
			a-=3;
		}
		if(a==-2){//mod 3 == 1
			p<<=1;
			a+=3;
		}
	}
	return A;
}
