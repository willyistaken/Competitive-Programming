#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<int> basis;

void addstuff(int k){
	int g = k;
	for(auto i : basis){
		g=  min(g,g^i);
	}
	if(g) basis.push_back(g);
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n = 5000;
	for(int i=0;i<1e6;i++){
		addstuff(i);
		if(basis.size()>=n) break;
	}
	for(auto i : basis) cout<<i<<" ";
	

	return 0;
}
