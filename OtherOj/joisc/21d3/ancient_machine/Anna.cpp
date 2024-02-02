#include "Anna.h"
#include <vector>

namespace {

int variable_example = 0;

}

void Anna(int N, std::vector<char> S) {
	for(int i=0;i<N;i++){
		if(S[i]=='X'){
			Send(0);
			Send(0);
		}
		if(S[i]=='Y'){
			Send(0);
			Send(1);
		}
		if(S[i]=='Z'){
			Send(1);
			Send(0);
		}
	}
}
