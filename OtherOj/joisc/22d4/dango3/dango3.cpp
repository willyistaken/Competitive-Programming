#include "dango3.h"

#include <vector>
#include<random>
#include<algorithm>
#include<iostream>
#include<cassert>
using namespace std;
namespace {

int variable_example = 1;
int n,m;
}  // namespace

void process(vector<int> &get,vector<int> &pos) {
    int k = pos.size();
    random_shuffle(pos.begin(),pos.end());
    vector<int> a;
    for(int i=1; i<k; i++) a.push_back(pos[i]);
    vector<bool> notin(k,0);
    notin[0]=1;
    int should = (k/n)-1;
	int cnt = 1;
    for(int i=1; i<k; i++) {
		if(cnt==n) break;
        notin[i]=1;
        vector<int> q;
        for(int i=0; i<k; i++) if(!notin[i]) q.push_back(pos[i]);
        int g = Query(q);
        if(g!=should) notin[i]=0;
		else{
			cnt++;	
		}
    }
    for(int i=0; i<k; i++) if(notin[i]) get.push_back(pos[i]);
}
void Solve(int N, int M) {
    n = N;
    m = M;
    vector<int> pos(N*M);
    vector<bool> in(N*M+1);
    for(int i=0; i<N*M; i++) pos[i] = i+1;
    for(int i=0; i<M-1; i++) {
        vector<int> get;
        process(get,pos);
        for(auto i : get) in[i]=1;
        assert(get.size()==n);
        Answer(get);
        vector<int> temp;
        for(auto i : pos) if(!in[i]) temp.push_back(i);
        swap(pos,temp);
    }
    Answer(pos);
}
