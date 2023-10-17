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
	n = p(gen)%50;
	cout<<n<<"\n";
	for(int i=0;i<n;i++){
		int a = p(gen);
		int b = p(gen);
		int c = p(gen);
		assert(a<=300 && b<=300 && c<=300 && a>0 && b>0 && c>0);
		cout<<a<<" "<<b<<" "<<c<<"\n";
	}
	return 0;
}
