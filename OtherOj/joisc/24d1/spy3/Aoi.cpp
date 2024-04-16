#include "Aoi.h"

namespace {

int variable_example = 0;


}  // namespace
using namespace std;
std::string aoi(int N, int M, int Q, int K, std::vector<int> A,
  std::vector<int> B, std::vector<long long> C,
  std::vector<int> T, std::vector<int> X) {
  string ans = "";
  for(int i=0;i<K;i++){
	  for(int b=0;b<40;b++)	{
	  	char a = ((C[X[i]]>>b)&1)?('1'):('0');
		ans.push_back(a);
	  }
  }
  return ans;
}
