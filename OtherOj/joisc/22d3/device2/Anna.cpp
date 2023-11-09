#include "Anna.h"
#include <utility>
#include <vector>
using namespace std;
namespace {

}

int Declare() {
  return 180;
}

std::pair<std::vector<int>, std::vector<int> > Anna(long long A) {
	vector<int> X;
	vector<int> Y;
	for(int i=0;i<60;i++){
		for(int k=0;k<3;k++){
			if((A>>i)&1) X.push_back(1);
			else X.push_back(0);
		}
	}
	for(int i=1;i<=180;i++){
		if(i&1) Y.push_back(1);
		else Y.push_back(0);
	}
  	return make_pair(X, Y);
}
