#include "Benjamin.h"
#include <string>
#include <vector>
using namespace std;
 
namespace {
	int blo_siz=30;
	int blo_num=(1<<10);
	int max_pot=14;
	int X, Y;
string enc(int a){
	string res(10, '0');
	for(int i=0; i<10; i++){
		res[i]='0'+!!(a&(1<<i));
	}
	return res;
}
int dec(string s){
	int res=0;
	for(int i=0; i<s.size(); i++){
		res+=(1<<i)*(s[i]-'0');
	}
	return res;
}
}
 
string SendB(int N, int _X, int _Y) {
	X=_X;
	Y=_Y;
	if(X>Y)swap(X, Y);
	return enc(X/blo_siz)+enc(Y/blo_siz);
}
 
int Answer(string s) {
	int mini=dec(s.substr(0, max_pot));
	vector<int> blo1(blo_siz), blo2(blo_siz);
	blo1[0]=dec(s.substr(max_pot, max_pot));
	for(int i=1; i<blo_siz;i++){
		if(s[max_pot*2-1+i]=='1')blo1[i]=blo1[i-1]+1;
		else blo1[i]=blo1[i-1]-1;
	}
	blo2[0]=dec(s.substr(2*max_pot+blo_siz-1, max_pot));
	for(int i=1; i<blo_siz;i++){
		if(s[max_pot*3+blo_siz-2+i]=='1')blo2[i]=blo2[i-1]+1;
		else blo2[i]=blo2[i-1]-1;
	}
	int ans=blo1[X%blo_siz]+blo2[Y%blo_siz];
	for(int i=X%blo_siz;i<blo_siz; i++){
		mini=min(mini, blo1[i]);
	}
	for(int i=Y%blo_siz;i>=0; i--){
		mini=min(mini, blo2[i]);
	}
	return ans-2*mini;
}

