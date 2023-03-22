#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




ll m,k,d;
void print(ll k){
	for(int i=m-1;i>=0;i--)	{
		if(k&(1LL<<i)) cout<<1;
		else cout<<0;
	}
	cout<<"\n";
}


signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>m>>k>>d;
	vector<ll> stuff;
	for(ll i=0;i<(1<<m);i++){
		if(__builtin_popcount(i)==k) stuff.push_back(i);
	}
	vector<ll> s;
	for(auto i : stuff){
		bool work = 1;
		for(auto j : s){
			if(__builtin_popcount(i&j)>d){
				work = 0;
				break;
			}
		}
		if(work) s.push_back(i);
	}
	cout<<s.size()<<"\n";
	for(auto i : s) print(i);
	return 0;
}
