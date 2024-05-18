#include "perm.h" 
#include<bits/stdc++.h>
using namespace std;
std::vector<int> construct_permutation(long long k)
{
	deque<int> d;
	int f = __lg(k);
	int cur = 0;
	for(int i=f-1;i>=0;i--){
		d.push_back(cur++);
		if((k>>i)&1) d.push_front(cur++);
	}
	vector<int> ans;
	for(auto i : d) ans.push_back(i);
	return ans;
}
