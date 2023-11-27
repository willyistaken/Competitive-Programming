#include "Bruno.h"
#include <vector>
#include<iostream>
using namespace std;
namespace {
const int B = 51;
int n;
int arr[1000000];
int count;
int ans = 0;
bool FunctionExample(bool P) {
  return !P;
}

}  // namespace

void InitB(int N, std::vector<int> P) {
  n = N;
  for(int i = 0; i < N; i++) {
    arr[i] = P[i];
  }
  int LB = 0;
  int RB = 0;
  for(int i=0;i<9;i++){
  	ans = -1;	
	SendB(1);
	int tri = ans+1;
	LB*=3;
	LB+=tri;
  }
  for(int i=0;i<9;i++){
  	ans = -1;
	SendB(1);
	int tri = ans+1;
	RB*=3;
	RB+=tri;
  }
  cout<<LB<<" "<<RB<<"\n";
  int l = B*(LB+1);
  int r = B*(RB)-1;
  pair<int,int> BTnum = {1e9,1e9};
  for(int i=l;i<=r && i<n;i++) BTnum = min(BTnum,{arr[i],i});
  for(int i=19;i>=0;i--){
  	SendB((BTnum.first>>i)&1);
  }
  for(int i=19;i>=0;i--){
  	SendB((BTnum.second>>i)&1);
  }
  for(int i=0;i<B;i++){
  	int loc = i+B*(LB);
	int G = (1<<20)-1;
	if(loc<n) G = arr[loc];
	for(int i=19;i>=0;i--){
		SendB((G>>i)&1);
	}
  }
  for(int i=0;i<B;i++){
  	int loc = i+B*(RB);
	int G = (1<<20)-1;
	if(loc<n) G = arr[loc];
	for(int i=19;i>=0;i--){
		SendB((G>>i)&1);
	}
  }
}

void ReceiveB(bool y) {
	ans = (int)y;
}
