#include "Anna.h"
#include "Bruno.h"
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <random>

namespace {

void WrongAnswer(int code) {
  printf("Wrong Answer [%d]\n", code);
  exit(0);
}

const int M_LIMIT = 2000;
int Q;
long long A;
std::mt19937 rng;

std::vector<int> riffle_shuffle(std::vector<int> s, std::vector<int> t) {
  std::vector<int> broken((int)s.size() * 2, 0);
  for (int i = 0; i < (int)s.size(); i++) {
    while (true) {
      int idx = std::uniform_int_distribution<int>(0, (int)s.size() * 2 - 1)(rng);
      if (broken[idx] == 0) {
        broken[idx] = 1;
        break;
      }
	}
  }
  std::vector<int> u;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < (int)broken.size(); i++) {
    if (broken[i] == 0) { u.push_back(s[cnt1]); cnt1 += 1; }
    if (broken[i] == 1) { u.push_back(t[cnt2]); cnt2 += 1; }
  }
  return u;
}

}

int main(int argc, char **argv) {
  long long seed = 0;
  if (argc >= 2) {
    seed = atoll(argv[1]);
  }
  rng = std::mt19937(seed);
	
  if (scanf("%d", &Q) != 1) {
    fprintf(stderr, "Error while reading input\n");
    exit(1);
  }
  
  int m = Declare();
  if (!(m >= 1 && m <= M_LIMIT)) WrongAnswer(1);
  
  for (int scenario = 0; scenario < Q; scenario++) {
    if (scanf("%lld", &A) != 1) {
      fprintf(stderr, "Error while reading input\n");
      exit(1);
    }
    std::pair<std::vector<int>, std::vector<int> > st = Anna(A);
    std::vector<int> s = st.first;
    std::vector<int> t = st.second;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] != 0 && s[i] != 1) WrongAnswer(2);
	}
    for (int i = 0; i < (int)t.size(); i++) {
      if (t[i] != 0 && t[i] != 1) WrongAnswer(2);
	}
	if (s.size() != t.size()) WrongAnswer(4);
	if (!(1 <= (int)s.size() && (int)s.size() <= m)) WrongAnswer(3);
    
    std::vector<int> u = riffle_shuffle(s, t);
    long long Answer = Bruno(u);
    if (Answer != A) WrongAnswer(5);
  }
  
  printf("Accepted: %d\n", m);
  return 0;
}
