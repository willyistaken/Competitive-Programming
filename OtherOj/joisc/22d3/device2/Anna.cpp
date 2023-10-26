#include "Anna.h"
#include <utility>
#include <vector>
using namespace std;
namespace {
const int P = 30;
int variable_example = 0;

}

int Declare() {
  return P*63;
}

std::pair<std::vector<int>, std::vector<int> > Anna(long long A) {
	vector<int> X;
	vector<int> Y;
	for(int i=0;i<P*63;i++) Y.push_back(0);
	for(int i=0;i<63;i++){
		X.push_back(((A>>i)&1));
		for(int i=0;i<P-1;i++) X.push_back(0);
	}
  	return make_pair(X, Y);
}
