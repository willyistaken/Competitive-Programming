#include "Anna.h"
#include <vector>
#include<iostream>
using namespace std;
namespace {

int triL[9];
int triR[9];
const int B = 51;
int n, l, r;
int count;
int BTnum = 0;
int BTind = 0;
int RL[B];
int RR[B];
}  // namespace
void InitA(int N, int L, int R) {
  BTnum=0;
  BTind = 0;
  count=0;
  for(int i=0;i<9;i++){
  	triL[i]=0;
  	triR[i]=0;
  }
  for(int i=0;i<B;i++){
  	RL[i]=0;
	RR[i]=0;
  }
  n = N;
  l = L;
  r = R;
  int bl = l/B;
  int br = r/B;
  for(int i=8;i>=0;i--){
  	triL[i] = (bl%3)-1;
	triR[i] = (br%3)-1;
	bl/=3;
	br/=3;
  }
}

void ReceiveA(bool x) {
	count++;			
	if(count<=18){
		int i = count-1;
		if(count<=9){
			if(triL[i]>=0) SendA(triL[i]==1);
		}else{
			if(triR[i]>=0) SendA(triR[i]==1);
		}
	}else{
		if(count>=19 && count<=38){
			BTnum<<=1;	
			BTnum+=x;
		}else if(count>=39 && count<=58){
			BTind<<=1;
			BTind+=x;
		}else{
			if(count<=1078){
				RL[((count-59)/20)]*=2;	
				RL[((count-59)/20)]+=x;
			}else{
				RR[((count-1079)/20)]*=2;	
				RR[((count-1079)/20)]+=x;
			}
		}
	}
}

int Answer() {
	pair<int,int> minn = {1e9,-1};
	minn = min(minn,{BTnum,BTind});
	
	for(int i=0;i<B;i++) cout<<RL[i]<<" ";
	cout<<"L\n";
	for(int i=0;i<B;i++) cout<<RR[i]<<" ";
	cout<<"R\n";
	
	int rl = l%B;		
	int rr = r%B;
	if(l/B==r/B){
		for(int i=rl;i<=rr;i++) minn = min(minn,{RL[i],B*(l/B)+i});
	}else{
		for(int i=rl;i<B;i++) minn = min(minn,{RL[i],B*(l/B)+i});
		for(int i=rr;i>=0;i--) minn = min(minn,{RR[i],B*(r/B)+i});
	}
	cout<<minn.second<<"!\n";
	return minn.second;
}
