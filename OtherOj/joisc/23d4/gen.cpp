#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	mt19937 gen(time(0));
	auto p = uniform_int_distribution<int>(0,1000);
	n = (p(gen)%5)+1;
	cout<<n<<"\n";
	vector<int> arr;
	for(int i=0;i<n;i++) arr.push_back(p(gen));
	sort(arr.begin(),arr.end());
	for(auto i : arr) cout<<i<<" ";
	cout<<"\n";
	cout<<1<<"\n"<<p(gen)<<"\n";
	return 0;
}
