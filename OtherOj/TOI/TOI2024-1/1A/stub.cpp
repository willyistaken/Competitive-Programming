/**
This is a simple wrapper for communication with the manager.
DO NOT CHANGE THIS FILE!!!!!
**/

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
using std::vector;
using std::stringstream;
using std::string;
using std::to_string;

// Functions to be implemented in the solution.
vector<int> detect_debris(int n, int m, int L, int R);

// Functions provided to the solution.
vector<int> activate_sonar_system(int k, const vector<int>& p);

////////////////////////////////////////////////
namespace {  // Used in this file only.
void run();
FILE *fifo_in, *fifo_out;
void _send_msg(const string& msg, const vector<int>& p);
void _send_msg(const string& msg, const int k, const vector<int>& p);
int _recv_int();
vector<int> _recv_int_vector();
}  // namespace
////////////////////////////////////////////////

int main(int argc, char **argv) {

    // IF YOU WANT TO TEST LOCALLY ON YOUR COMPUTER,
    // 如果你想要在本地端測試你的程式，
    // COMMENT THESE TWO LINES AND UNCOMMENT THE TWO LINES BELOW.
    // 把下面這兩行註解起來，然後把更下面兩行打開，這樣就可以從命令列互動了。
    fifo_in = fopen(argv[1], "r");
    fifo_out = fopen(argv[2], "w");
    // fifo_in = stdin;
    // fifo_out = stdout;

    run();

    fclose(fifo_in);
    fclose(fifo_out);
    return 0;
}

////////////////////////////////////////////////
namespace {

void _send_msg(const string& msg, const vector<int>& nums) {

    if (fifo_out == stdout) {
      // 本地測試
      stringstream query;
      query << msg << ':';
      for (size_t i = 0; i < nums.size(); i++) {
        query << ' ' << nums[i];
      }
      fprintf(fifo_out, "%s\n", query.str().c_str());
      fflush(fifo_out);
      return;
    }

    string query = msg + " " + to_string(nums.size());
    fprintf(fifo_out, "%s", query.c_str());
    stringstream qs("");
    for (size_t i = 0; i < nums.size(); ++i) {
      qs << ' ' << nums[i];
    }
    fprintf(fifo_out, "%s\n", qs.str().c_str());
    fflush(fifo_out);
}

void _send_msg(const string& msg, const int k, const vector<int>& nums) {

    if (fifo_out == stdout) {
      // 本地測試
      stringstream query;
      query << msg << ':' << " 區間長度 k=" << k << "; 位置:";
      for (size_t i = 0; i < nums.size(); i++) {
        query << ' ' << nums[i];
      }
      fprintf(fifo_out, "%s\n請輸入一個長度恰好為 m 的 0-1 字串代表結果:\n", query.str().c_str());
      fflush(fifo_out);
      return;
    }

    string query = msg + " " + to_string(k) + " " + to_string(nums.size());
    fprintf(fifo_out, "%s", query.c_str());
    stringstream qs("");
    for (size_t i = 0; i < nums.size(); ++i) {
      qs << ' ' << nums[i];
    }
    fprintf(fifo_out, "%s\n", qs.str().c_str());
    fflush(fifo_out);
}

int _recv_int() {
    int val;
    int ret = fscanf(fifo_in, "%d", &val);
    // Receives error.
    if (ret != 1 || val == -1) {
        fclose(fifo_in);
        fclose(fifo_out);
        exit(0);
    }
    return val;
}

vector<int> _recv_int_vector() {
  vector<int> vals;

  if (fifo_in == stdin) {
    char s[500];
    fscanf(fifo_in, "%s", s);
    for(int i=0;s[i];i++) vals.push_back(s[i]=='1');
    return vals;
  }

  int k = _recv_int();
  // Something wrong.
  if (k <= 0 || k > 100) {
    fclose(fifo_in);
    fclose(fifo_out);
    exit(0);
  }
  vals.resize(k);
  for (int i = 0; i < k; i++) {
    vals[i] = _recv_int();
  }
  return vals;
}

void run() {
  if (fifo_out == stdout) {
    fprintf(fifo_out, "請輸入 T (測資筆數):\n");
  }
  int T = _recv_int();
  for (int i = 0; i < T; i++) {
    if (fifo_out == stdout) {
      fprintf(fifo_out, "Test %d/%d: 請輸入 n, m, L, R:\n", i+1, T);
    }
    int n = _recv_int();
    int m = _recv_int();
    int L = _recv_int();
    int R = _recv_int();

    vector<int> answer = detect_debris(n, m, L, R);
    _send_msg("done", answer);
  }
}
}  // namespace

vector<int> activate_sonar_system(int k, const vector<int> &p) {
  _send_msg("activate", k, p);
  return _recv_int_vector();
}
