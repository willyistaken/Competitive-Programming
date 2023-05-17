#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <algorithm>
#include<map>
#include<iostream>

using namespace std;

namespace {
    const int MAX_VALUE_OF_N = 100;
    const int MAX_VALUE_OF_Q = 200;
    int numberOfQueries = 0;
    int n;
    std::vector<int> a;

    void wrong_answer(string s) {
		cout<<s<<"\n";
        printf("-1\n");
        exit(0);
    }
}

void query() {
    numberOfQueries++;

    if (numberOfQueries > MAX_VALUE_OF_Q) {
        wrong_answer("Number of queries exceeded");
    }
}

int ask(int position) {
    query();
    
    if (position < 1 || position > n) {
        wrong_answer("Not correct position");
    }
    return a[position - 1];

}
vector<int> get_pairwise_xor(vector<int> positions) {
    query();
    
    if (positions.empty() || positions.size() > n) {
        wrong_answer("Not correct size");
    }
    
    sort(positions.begin(), positions.end());
    
    for (int i = 1; i < positions.size(); i++) {
        if (positions[i] == positions[i - 1]) {
            wrong_answer("Not unique");
        }
    }

    for (int i = 0; i < positions.size(); i++) {
        if (positions[i] < 1 || positions[i] > n) {
            wrong_answer("Not correct position");
        }
    }

    vector<int> pairwise_xor;
    
    for (int i = 0; i < positions.size(); i++) {
        for (int j = 0; j < positions.size(); j++) {
            pairwise_xor.push_back(a[positions[i] - 1] ^ a[positions[j] - 1]);
        }
    }
    sort(pairwise_xor.begin(), pairwise_xor.end());

    return pairwise_xor;
}


vector<int> guess(int n);




int main() {
    assert(scanf("%d", &n) == 1);

    assert(1 <= n && n <= MAX_VALUE_OF_N);
    
    for (int i = 1; i <= n; i++) {
        int x;

        assert(scanf("%d", &x) == 1);
        assert(x >= 0 && x <= 1000 * 1000 * 1000);

        a.push_back(x);
    }
    vector<int> participant_solution = guess(n);
    if (participant_solution.size() != n) {
		printf("adf");
		return 0;
    }

	printf("%d\n", n);
    
    for (auto i: participant_solution) {
        printf("%d ", i);
    }
    printf("\n");
    printf("%d\n", numberOfQueries);
    return 0;
}

int base;

vector<int> getarr(vector<int> pos){
	vector<int> s;
	if(pos.empty()) return s;
	vector<int> s1 = get_pairwise_xor(pos);
	pos.push_back(1);
	vector<int> s2 = get_pairwise_xor(pos);
	map<int,int> st;
	for(auto i : s2) st[i]++;
	for(auto i : s1) st[i]--;
	for(auto i : st){
		if(i.first!=0 && i.second) s.push_back(i.first^base);
	}
	return s;
}

map<int,int> mp;
vector<int> guess(int n){
	base  = ask(1);
	for(int i=0;i<7;i++){
		vector<int> pos;	
		for(int k=2;k<=n;k++){
			if(k&(1<<i)) pos.push_back(k);
		}
		vector<int> val = getarr(pos);
		for(auto g : val) mp[g]+=(1<<i);
	}
	vector<int> arr(n);
	for(auto i : mp){
		arr[i.second-1] = i.first;
	}
	arr[0] = base;
	return arr;
}

