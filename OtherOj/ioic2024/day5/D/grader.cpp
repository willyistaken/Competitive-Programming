#include "lib0046.h"
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

const int MAX_OP = 768;

void fatal(const string& msg) {
    cerr << msg << endl;
    exit(1);
}

void ensureImpl(bool condition, const char* conditionStr) {
    if (condition)
        return;
    fatal("Condition does not satisfy: " + string(conditionStr));
}

int TESTING = 0;
void debug(){if (TESTING) cerr << endl;}
template<class T, class ... U> void debug(T a, U ...b) {if (TESTING) cerr << a << " ", debug(b...);}

#define ensure(x...) ensureImpl(x, #x)

using num = int;
const int K = 49;
const num ONE = -1;

int NUM_OPS = 0;
static num reg[K];

double to_double(num x) {
	double ret = 0, cur = -128;
	for (int i = 31;i >= 0;i--) {
		if ((x>>i) & 1) ret += cur;
		if (i == 31) cur = -cur;
		cur /= 2;
	}
	return ret;
}
num to_num(double x) {
	double cur = 64;
	num ret = 0;
	if (x < 0) ret |= 1LL<<31;
	for (int i = 30;i >= 0;i--) {
		if (x >= cur) {
			ret += 1LL<<i;
			x -= cur;
		}
		cur /= 2;
	}
	return ret;
}

void setbit(int t, int b, int val) { //used by grader, sets bit of register
	reg[t] ^= reg[t]&(1LL<<b);
	reg[t] |= ((num)val)<<b;
}

void store(std::string s, int t) {
	NUM_OPS++;
	debug("store", s, t);
	ensureImpl(s.size() == 32, "s.size() != 32");
	ensureImpl(0 <= t && t < K, "t out of range");
	for (int i = 0;i < 32;i++) {
		ensureImpl(s[i] == '0' || s[i] == '1', "s is not a 01 string");
		setbit(t, i, s[i]-'0');
	}
}
void storebit(int x, int b, int t, int d) {
	debug("storebit", x, b, t, d);
	NUM_OPS++;
	ensureImpl(0 <= x && x < K, "x out of range");
	ensureImpl(0 <= b && b < 32, "b out of range");
	ensureImpl(0 <= t && t < K, "t out of range");
	ensureImpl(0 <= d && d < 32, "d out of range");
	setbit(t, d, (reg[x]>>b)&1);
}
void prop(int x, int b, int t){
	debug("prop", x, b, t);
	NUM_OPS++;
	ensureImpl(0 <= x && x < K, "x out of range");
	ensureImpl(0 <= b && b < 32, "b out of range");
	ensureImpl(0 <= t && t < K, "t out of range");
	int val = (reg[x]>>b)&1;
	for (int i = 0;i < 32;i++) {
		setbit(t, i, val);
	}
}
void flip(int x, int t) {
	debug("flip", x, t);
	ensureImpl(0 <= x && x < K, "x out of range");
	ensureImpl(0 <= t && t < K, "t out of range");
	reg[t] = ~reg[x];
}
void left(int x, int p, int t) {
	debug("left", x, p);
	NUM_OPS++;
	ensureImpl(0 <= x && x < K, "x out of range");
	ensureImpl(0 <= p && p < 32, "p out of range");
	ensureImpl(0 <= t && t < K, "t out of range");
	reg[t] = reg[x]<<p;
}
void right(int x, int p, int t){
	debug("right", x, p);
	NUM_OPS++;
	ensureImpl(0 <= x && x < K, "x out of range");
	ensureImpl(0 <= p && p < 32, "p out of range");
	ensureImpl(0 <= t && t < K, "t out of range");
	reg[t] = reg[x]>>p;
}

// const int OP_LESS = 0;
// const int OP_LEQ = 1;
// const int OP_GREATER = 2;
// const int OP_GEQ = 3;
void compare(int x, int y, int cmp, int t){
	debug("compare", x, y, cmp, t);
	NUM_OPS++;

	ensureImpl(0 <= x && x < K, "x out of range");
	ensureImpl(0 <= y && y < K, "y out of range");
	ensureImpl(0 <= cmp && cmp < 4, "cmp out of range");
	ensureImpl(0 <= t && t < K, "t out of range");
	bool res = 0;
	if (cmp == OP_LESS) res = reg[x] < reg[y];
	else if (cmp == OP_LEQ) res = reg[x] <= reg[y];
	else if (cmp == OP_GREATER) res = reg[x] > reg[y];
	else if (cmp == OP_GEQ) res = reg[x] >= reg[y];
	if (res) reg[t] = ONE;
	else reg[t] = 0;
}
// const int OP_AND = 0;
// const int OP_OR = 1;
// const int OP_XOR = 2;
// const int OP_ADD = 3;
// const int OP_SUBTRACT = 4;
void calculate(int x, int y, int op, int t) {
	debug("calculate", x, y, op, t);
	NUM_OPS++;

	ensureImpl(0 <= x && x < K, "x out of range");
	ensureImpl(0 <= y && y < K, "y out of range");
	ensureImpl(0 <= op && op < 5, "cmp out of range");
	ensureImpl(0 <= t && t < K, "t out of range");
	long long tmp = reg[x];
	if (op == OP_AND) tmp &= reg[y];
	else if (op == OP_OR) tmp |= reg[y];
	else if (op == OP_XOR) tmp ^= reg[y];
	else if (op == OP_ADD) tmp += reg[y];
	else if (op == OP_SUBTRACT) tmp -= reg[y];

	ensureImpl(INT_MIN <= tmp && tmp <= INT_MAX, "result cannot be stored");
	reg[t] = tmp;
}
void print(int x) {
	debug("print", x);
	ensureImpl(0 <= x && x < K, "x out of range");
	cerr << "Value of a[" <<  x << "] is: " << to_double(reg[x]) << endl;
}
void printstr(int x) {
	debug("printstr", x);
	cerr << "Value of a[" <<  x << "] is: ";
	for (int i = 0;i < 31;i++) cerr << ((reg[x]>>i)&1);
	cerr << endl;
}
static num ans;
static bool answered = false;
void answer(int x) {
	debug("answer", x);
	ensureImpl(!answered, "already answered");
	answered = true;
	ensureImpl(0 <= x && x < K, "x out of range");
	ans = reg[x];	
}
const double PI = acos(-1);
int main() {
	int problem_type;
	num x;
	double val;
	cin >> problem_type;
	ensureImpl(1 <= problem_type && problem_type <= 4, "Problem type must be 1,2,3,4");
	cin >> val;
	x = to_num(val);
	reg[0] = x;
	printstr(0);
	solve(problem_type);	
	double pans = to_double(ans);
	double jans = 0;
	if (problem_type == 1) jans = val*2;
	else if (problem_type == 2) jans = val*val;
	else if (problem_type == 3) jans = sin(val / 180 * PI);
	else if (problem_type == 4) jans = log10(val);
	if (NUM_OPS > MAX_OP) {
		cerr << "WA: Too Many Operations" << endl;
		return 0;
	}
	cerr << "Total Operations: " << NUM_OPS << endl;
	double abs_error = abs(pans - jans);
	double rel_error = (jans == 0 ? 1e18 : abs_error / jans);
	cerr << fixed << setprecision(10) << "Error: " << min(abs_error, rel_error) << endl;
	if (min(abs_error, rel_error) <= 1e-5) {
		cerr << fixed << setprecision(10) << "AC: Calculated " << pans << ", Judge Answer " <<  jans << endl;
	} else {
		cerr << fixed << setprecision(10) << "WA: Calculated " << pans << ", Judge Answer " <<  jans << endl;
	}
    return 0;
}

