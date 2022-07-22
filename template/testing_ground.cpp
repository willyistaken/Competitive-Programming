#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int r = 1;
	for(int i=0;i<64;i++){
		r = (r*5)%1234;
	}
	cout<<r;
	return 0;
}
