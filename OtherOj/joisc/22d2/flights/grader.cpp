#include "Ali.h"
#include "Benjamin.h"
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <algorithm>

namespace {

void WrongAnswer(int code) {
  printf("Wrong Answer [%d]\n", code);
  exit(0);
}

const int SENDA_LIMIT = 300'000;
const int SENDB_LIMIT = 20;
int Q, N, x, y;
int IDcount = 0;
int CurrentMaxLength = 0;
std::vector<int> AirportID;

}

void SetID(int p, int value) {
  if (p < 0 || p >= N) WrongAnswer(1);
  if (value < 0 || value > 2 * N + 19) WrongAnswer(2);
  if (AirportID[p] != -1) WrongAnswer(3);
  AirportID[p] = value;
  IDcount += 1;
}

int Solve() {
  IDcount = 0;
  AirportID.clear();
  
  if (scanf("%d%d%d", &N, &x, &y) != 3) {
    fprintf(stderr, "Error while reading input\n");
    exit(1);
  }
  std::vector<int> U(N-1), V(N-1);
  for (int i = 0; i < N - 1; i++) {
    if (scanf("%d%d", &U[i], &V[i]) != 2) {
      fprintf(stderr, "Error while reading input\n");
      exit(1);
    }
  }
  AirportID.resize(N, -1);
  
  Init(N, U, V);
  if (IDcount != N) WrongAnswer(4);
  
  std::string SB = SendB(N, AirportID[x], AirportID[y]);
  if ((int)SB.size() != SENDB_LIMIT) WrongAnswer(7);
  for (int i = 0; i < (int)SB.size(); i++) {
    if (SB[i] != '0' && SB[i] != '1') WrongAnswer(8);
  }
  
  std::string SA = SendA(SB);
  if ((int)SA.size() == 0 || (int)SA.size() > SENDA_LIMIT) WrongAnswer(5);
  for (int i = 0; i < (int)SA.size(); i++) {
    if (SA[i] != '0' && SA[i] != '1') WrongAnswer(6);
  }
  
  int YourAnswer = Answer(SA);
  CurrentMaxLength = std::max(CurrentMaxLength, (int)SA.size());
  return YourAnswer;
}

int main() {
  if (scanf("%d", &Q) != 1) {
    fprintf(stderr, "Error while reading input\n");
    exit(1);
  }
  
  for (int scenario = 0; scenario < Q; scenario++) {
    int YourAnswer = Solve();
    printf("Scenario %d: Your Answer = %d\n", scenario, YourAnswer);
  }
  
  printf("Accepted: Maximum Length = %d\n", CurrentMaxLength);
  return 0;
}
