#include "Bruno.h"
#include <utility>
#include <vector>
#include<iostream>
using namespace std;
namespace {
const int P = 10;
int variable_example = 0;

}

long long Bruno(std::vector<int> u) {
	long long A = 0;		
	int sz = u.size();
	for(int i=0;i<sz;i++){
		if(u[i]==1) A+=(1LL<<(i/(2*P)+1));
	}
//	cerr<<A<<"\n";
	return A;
}
