#include "Bruno.h"
#include <vector>
#include<bits/stdc++.h>
using namespace std;

namespace {

int variable_example = 0;

int FunctionExample(int P) { return 1 - P; }

}  // namespace

void Bruno(int N, int L, std::vector<int> A) {
	vector<int> arr(N);
	for(int i=0;i<N;i++){
		int c = 2*A[2*i] + A[2*i+1];
		arr[i]=c;
	}
		
}
