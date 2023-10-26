#include "Benjamin.h"
#include <string>
#include <vector>
#include<iostream>

namespace {
int x;
int y;
int n;
}

std::string SendB(int N, int X, int Y) {
	n = N;
	x= X;
	y = Y; int xm = X%1024;
	int ym = Y%1024;
	std::string re;
	for(int i=0;i<10;i++){
		if(xm&1) re.push_back('1');
		else re.push_back('0');
		xm>>=1;
	}
	for(int i=0;i<10;i++){
		if(ym&1) re.push_back('1');
		else re.push_back('0');
		ym>>=1;
	}
	return re;
}

int Answer(std::string T) {
//	std::cout<<T<<std::endl;
//	if(x>y) std::swap(x,y);
//	std::cout<<x<<"this"<<y<<"\n";
	int depx = 0; int depy = 0;
	for(int i=0;i<14;i++){
		if(T[14*(x/1024)+i]=='1') depx+=(1<<i);
		if(T[140+14*(y/1024)+i]=='1') depy+=(1<<i);
	}
//std::cout<<depx<<" && "<<depy<<std::endl;
	if(x%1024>y%1024) std::swap(x,y);
	int l = (2*(x/1024));
	int r = (2*(y/1024))+1;
	//std::cout<<l<<" "<<r<<std::endl;
	if(l>r)	 std::swap(l,r);
	int minn = 1e9;
	for(int i=l;i<r;i++){
		int dd = 0;
		for(int p=0;p<14;p++){
			if(T[14*(20+i)+p]=='1') dd+=(1<<p);
		}
		//std::cout<<dd<<"->";
		minn = std::min(dd,minn);
	}
//	std::cout<<"\n";
//	std::cout<<depx<<" "<<depy<<"\n";
	return depx+depy-2*minn;
}
