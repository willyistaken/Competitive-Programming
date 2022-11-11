#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string a;cin>>a;
	sort(a.begin(),a.end());
	int cnt =1;
	while(next_permutation(a.begin(),a.end())){
		cnt++;
	}
	cout<<cnt<<"\n";
	cout<<a<<"\n";
	while(next_permutation(a.begin(),a.end())){
		cout<<a<<"\n";
	}
	return 0;
}
