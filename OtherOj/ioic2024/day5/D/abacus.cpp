#include "lib0046.h"

// definition of operations (already defined in header)
// const int OP_LESS = 0;
// const int OP_LEQ = 1;
// const int OP_GREATER = 2;
// const int OP_GEQ = 3;

// const int OP_AND = 0;
// const int OP_OR = 1;
// const int OP_XOR = 2;
// const int OP_ADD = 3;
// const int OP_SUBTRACT = 4;

// constant strings that might be useful
std::string zero_str = "00000000000000000000000000000000";
std::string one_str = "00000000000000000000000010000000";
std::string sign_str = "00000000000000000000000000000001";
std::string full_str = "11111111111111111111111111111111";
std::string unit_str = "10000000000000000000000000000000";
std::string dtr = 	   "10001011111011100010000000000000";
std::string os = 	   "01010101010101010101010000000000";
std::string otw = 	   "01000100010001000100000000000000";
std::string on = 	   "00000000000000000000000010000000";


void mul(int a,int b,int t){
	calculate(48,48,1,4);
	for(int i=0;i<32;i++){
		prop(a,i,1);
		calculate(b,1,0,2);
		if(i-24<=0){
			right(2,24-i,3);
		}else{
			left(2,i-24,3);
		}
		calculate(3,4,3,4);
	}
	calculate(4,48,2,t);
}

void solve(int problem_type) {
	if (problem_type == 1) { 		// double
		left(0, 1, 1);
		print(1);
		answer(1);
	} else if (problem_type == 2) { // square
		mul(0,0,5);
		answer(5);
	} else if (problem_type == 3) { // sine
		// 1 2 3 4are mul reserve			
		// 5, 6 7  are const
		// 8 is radient
		// 9 is ans
		store(dtr,5);
		store(os,6);
		store(otw,7);
		store(on,18);
		mul(0,5,8);
		mul(8,8,9);
		calculate(7,10,3,10);
		mul(9,10,10);
		calculate(10,6,4,10);
		mul(9,10,10);
		calculate(10,18,3,10);
		mul(10,8,10);
		answer(10);
	} else { 						// log
			 
	}
}
