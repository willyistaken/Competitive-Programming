#include "ancient2.h"
#include<bits/stdc++.h>
using namespace std;
namespace {

int variable_example = 1;

}  // namespace

std::string Solve(int N) {
	int B = (4*N)/5;
	string ans="";
	for(int i=1;i<B;i++){
		int m = i+2;
		vector<int> a(m);
		vector<int> b(m);
		for(int j=0;j<i-1;j++){
			a[j]=j+1;
			b[j]=j+1;
		}
		a[i-1] = i;
		b[i-1] = i+1;
		a[i]=i;
		b[i]=i;
		a[i+1]=i+1;
		b[i+1]=i+1;
		int k = Query(m,a,b);
		if(k==i) ans.push_back('0');
		else ans.push_back('1');
	}
	//20
	//01001001110100100111
	//01001001110100001111
	for(int i=B;i<=N;i++){
		int k = N-i+1;
		int m = 2*k;	
		vector<int> a(m);
		vector<int> b(m);
		for(int i=0;i<k;i++){
			a[i] = (i+1)%k;
			b[i] = (i+1)%k;
			a[i+k] = k+(i+1)%k;
			b[i+k] = k+(i+1)%k;
		}
		int f = N%k;
		b[f] = k;
		a[m-1] = (f+1)%k;
		int A = Query(m,a,b);
		if(A<k) ans.push_back('0');
		else ans.push_back('1');
	}
	return ans;
}
