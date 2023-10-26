#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	mt19937 gen(time(0));
	auto p = uniform_int_distribution<int>(1,300);
	n = p(gen)%5+1;
	cout<<n<<"\n";
	for(int i=0;i<n;i++){
		cout<<((p(gen)&1)?('a'):('b'));
	}
	cout<<"\n100\n1\n10\n";
	return 0;
}
