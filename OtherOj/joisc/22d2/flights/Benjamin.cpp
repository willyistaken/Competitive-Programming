#include "Benjamin.h"
#include <string>
#include <vector>

namespace {
int x;
int y;
int variable_example = 0;

}

std::string SendB(int N, int X, int Y) {
	x= X;
	y = Y;
	std::string s;
	int b = X^Y;
	for(int i=0;i<14;i++){
		if((b>>i)&1) s.push_back('1');
		else s.push_back('0');
	}
	for(int i=0;i<6;i++){
		if((X>>i)&1) s.push_back('1');
		else s.push_back('0');
	}
	return s;
}

int Answer(std::string T) {
  int g=0;
  for(int i=6;i<14;i++){
  	if((x>>i)&1) g+=(1<<(i-6));
  }
  int ans = 0;
  for(int i=0;i<14;i++){
  	 if(T[14*(g)+i]=='1') ans+=(1<<i);
  }
  return ans;
}
